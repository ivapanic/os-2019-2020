#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAXPROCESSES 200
#define MAXTIMES 10000000

static int num_of_processes;
static int times_add;
static int *A;
static int mem_id;

void process(int it, int pid, int ppid)
{
    for(int i = 0; i < times_add; ++i)
    {
        //printf("D: Proces: %d, prolaz: %d (pid=%d, ppid=%d)\n", it, i + 1, pid, ppid);
        A[0]++;
        //sleep(1);
    }
}


void free_mem(int sig)
{
    (void) shmdt((char *) A);
    (void) shmctl(mem_id, IPC_RMID, nullptr);
}

void check_input(int argc, char *argv[])
{
    if (argc != 3 || std::atoi(argv[1]) > MAXPROCESSES || std::atoi(argv[2]) > MAXTIMES)
    {
        std::cout << "Krivi argumenti. Dodaj <INT> broj procesa do " << MAXPROCESSES << " i <INT> broj ponavljanja do " << MAXTIMES << std::endl;
        exit(1);
    }
    else
    {
        num_of_processes = std::atoi(argv[1]);
        times_add = std::atoi(argv[2]);
    }
}


int main(int argc, char *argv[])
{
    check_input(argc, argv);

    mem_id = shmget(IPC_PRIVATE, sizeof(int), 0600);
    if (mem_id == -1)
    {
        std::cout << "Nema zajednicke memorije!" << std::endl;
        exit(1);
    }

    A = static_cast<int *>(shmat(mem_id, nullptr, 0));
    A[0] = 0;


    printf("R: pid=%d ppid=%d\n", getpid(), getppid());

    for (int i = 0; i < num_of_processes; ++i)
    {
        switch(int pid = fork())
        {
            case 1:
                std::cout << "Ne mogu stvoriti novi proces!" << std::endl;
                exit(1);
            case 0:
                process(i, getpid(), getppid());
                exit(0);
            default:
                break;

        }
    }


    for (int i = 0; i < num_of_processes; ++i)
    {
        wait(nullptr);
    }

    std::cout << "A=" << A[0] << std::endl;
    free_mem(0);


}