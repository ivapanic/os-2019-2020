#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include <vector>
#include <map>

static int n;
static bool partybreaker_in_the_room = false;
static std::map<int, int> counter; //how many times student has entered the room

static int students_in_the_room = 0;

pthread_mutex_t monitor;
static pthread_cond_t waiting;


void output(int is_a_partybreaker, int i, bool had_fun)
{
    if(is_a_partybreaker)
    {
        had_fun ? printf("Iz sobe napokon IZLAZI PARTIBREJKER. Party se moze nastaviti!\n") :
                printf("U sobu ULAZI PARTIBREJKER. Smara. Nitko ne ulazi dalje!\n");
    }
    else
    {
        had_fun ? printf("Iz sobe izlazi %d. student! U sobi je %d studenata!\n", i,  students_in_the_room) :
                printf("U sobu ulazi %d. student po %d. put! U sobi je %d studenata!\n", i, counter[i], students_in_the_room);
    }

}

void random_sleep_ms(int t_min, int t_max)
{
    usleep(rand() % (t_max * 1000 + 1 - t_min * 1000) + t_min * 1000); //sleep in milliseconds
}


void enter_room_S(int num) //student entering the room
{
    pthread_mutex_lock(&monitor);

    while(partybreaker_in_the_room)
        pthread_cond_wait(&waiting, &monitor);

    students_in_the_room++;
    counter[num]++;
    output(false, num, false);

    pthread_mutex_unlock(&monitor);
}


void enter_room_P() //partybreaker entering the room
{
    pthread_mutex_lock(&monitor);
    while(students_in_the_room < 3)
        pthread_cond_wait(&waiting, &monitor);

    partybreaker_in_the_room = true;
    output(true, 0, false);

    pthread_mutex_unlock(&monitor);
}


void exit_room_S(int num) //student exiting the room
{
    pthread_mutex_lock(&monitor);
    students_in_the_room--;
    output(false, num, true);

    pthread_cond_broadcast(&waiting);
    pthread_mutex_unlock(&monitor);
}


void exit_room_P() //partybreaker exiting the room
{
    pthread_mutex_lock(&monitor);
    while(students_in_the_room > 0)
        pthread_cond_wait(&waiting, &monitor);

    partybreaker_in_the_room = false;
    output(true, 0, true);

    pthread_cond_broadcast(&waiting);
    pthread_mutex_unlock(&monitor);
}


void *student(void *p)
{
    int num = *static_cast<int *>(p);

    int i = 0;

    while(i < 3)
    {
        random_sleep_ms(100, 500);
        enter_room_S(num);
        random_sleep_ms(1000, 2000);
        exit_room_S(num);
        i++;
    }
}


void *partybreaker(void *p)
{
    do
    {
        random_sleep_ms(100, 1000);
        enter_room_P();
        exit_room_P();
    } while (students_in_the_room > 0);

}


void signal_handler(int sig)
{
    exit(0);
}


void initialization()
{
    do
    {
        std::cout << "Zeljeni broj studenata u sobi (n > 3):" << std::endl;
        std::cin >> n;
    } while (n <= 3);

    sigset(SIGINT, signal_handler);
}

int main()
{
    initialization();
    pthread_t t[n + 1];
    int students[n + 1];

    srand(time(nullptr));

    pthread_create(&t[0], nullptr, partybreaker, nullptr);

    for(int i = 1; i <= n; ++i)
    {
        students[i] = i;

        if(pthread_create(&t[i], nullptr, student, &students[i]))
        {
            printf("Ne mogu stvoriti studenta br. %d!", students[i]);
            exit(1);
        }
    }
    
    for(int i = 0; i <= n; ++i)
    {
        pthread_join(t[i], nullptr);
    }
}