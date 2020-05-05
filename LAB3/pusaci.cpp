#include <iostream>
#include <semaphore.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <zconf.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define NUM_OF_PROCESSES 4

static std::map<int, std::string> ingredients; //mapped values for ingredients
static bool signal_flag; //shows if SIGINT has been received

static int *t1 = nullptr, *t2 = nullptr;
static int ID;
static sem_t *KO, *p1, *p2, *p3, *empty_table;


void output(int num_of_process)
{

    if (num_of_process == 0) //output for the dealer
        printf("Trgovac stavlja: %s i %s\n", ingredients[*t1].c_str(), ingredients[*t2].c_str());
    else //output for smokers
        printf("Pusac %d ima %s: uzima sastojke %s i %s te smota, zapali, pusi\n\n", num_of_process,
                ingredients[num_of_process].c_str(), ingredients[*t1].c_str(), ingredients[*t2].c_str());
}


void choose_ingredients()
{
    *t1 = rand() % 3 + 1;
    do
    {
        *t2 = rand() % 3 + 1;
    }
    while (*t1 == *t2);
}


void dealer()
{
    do {
        sleep(2); //beautifying output

        sem_wait(empty_table);
        sem_wait(KO); //enter KO

        choose_ingredients();
        output(0);

        sem_post(KO); //KO over
        sem_post(p1);
        sem_post(p2);
        sem_post(p3);

    } while(!signal_flag);
}


void wait_for_smoker(int num)
{

    switch(num)
    {
        case 1:
            sem_wait(p1);
            break;
        case 2:
            sem_wait(p2);
            break;
        case 3:
            sem_wait(p3);
            break;
        default:
            break;
    }
}


void smoker(int num)
{
    do
    {
        sleep(2); //beautifying output
        wait_for_smoker(num);
        sem_wait(KO); //enter KO

        if (*t1 != num  && *t2 != num)
        {
            output(num);
            sleep(2); //beautifying output
            sem_post(KO); //KO over
            sem_post(empty_table);
        }
        else
            sem_post(KO); //KO over

    } while(!signal_flag);
}


void delete_all(int sig)
{
    signal_flag = true;
    (void)shmctl(ID, IPC_RMID, nullptr);
    sem_destroy(KO); sem_destroy(p1); sem_destroy(p2); sem_destroy(p3);
    sem_destroy(empty_table);

    shmdt(KO);
    shmdt(p1); shmdt(p2); shmdt(p3);
    shmdt(empty_table);
    shmdt(t1); shmdt(t2);
    exit(0);
}


void semaphore_init()
{
    sem_init(KO, 1, 1);
    sem_init(p1, 1, 0); sem_init(p2, 1, 0); sem_init(p3, 1, 0);
    sem_init(empty_table, 1, 1);

}

void initialization()
{
    ingredients[0] = "GRESKA"; //for debugging purposes
    ingredients[1] = "papir";
    ingredients[2] = "duhan";
    ingredients[3] = "sibice";

    ID = shmget(IPC_PRIVATE, sizeof(sem_t) * 5, 0600);
    KO = static_cast<sem_t *>(shmat(ID, nullptr, 0));
    p1 = KO + 1; p2 = p1 + 1; p3 = p2 + 1;
    empty_table = p3 + 1;
    int table_id = shmget(IPC_PRIVATE, sizeof(int) * 2, 0600);
    t1 = static_cast<int *>(shmat(table_id, nullptr, 0));
    t2 = t1 + 1;

    semaphore_init();

    printf("Pusac 1: ima %s\n", ingredients[1].c_str());
    printf("Pusac 2: ima %s\n", ingredients[2].c_str());
    printf("Pusac 3: ima %s\n", ingredients[3].c_str());
    printf("------------------------------------------\n");

    switch(fork())
    {
        case -1:
            printf("Ne mogu stvoriti proces!\n");
            exit(1);
        case 0:
            dealer();
            exit(0);
        default:
            break;
    }

    for (int i = 1; i <= 3; ++i)
    {
        switch(fork())
        {
            case -1:
                printf("Ne mogu stvoriti proces pusaca br. %d!", i);
            case 0:
                smoker(i);
                exit(0);
            default:
                break;
        }
    }
}


int main()
{
    srand(time(NULL));
    initialization();
    sigset(SIGINT, delete_all);

    for(int i = 0; i < NUM_OF_PROCESSES; ++i)
    {
        wait(nullptr);
    }

    delete_all(0);

}