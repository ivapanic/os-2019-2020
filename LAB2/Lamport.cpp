#include <cstdio>
#include <cstdlib>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sys/wait.h>

#define MAXPROCESSES 20
#define MAXTIMES 1000000

static int *entering;
static int *number;
static int *memory;
static int *A;

static int num_of_processes;
static int times_add;
static int mem_id;


void process(int i)
{
    for (int j = 0; j < times_add; ++j)
    {
        A[0]++;
    }
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


int get_max_element(int arr[])
{
    int size_arr = sizeof(arr)/sizeof(arr[0]);
    int max_element = arr[0];
    for (int i = 1; i < size_arr; ++i)
    {
        if (arr[i] >= max_element)
            max_element = arr[i];
    }
    return max_element;
}

void enter_critical_section(int i)
{
    entering[i] = 1;
    number[i] = get_max_element(number) + 1;
    entering[i] = 0;

    for (int j = 0; j < num_of_processes; ++j)
    {
        while(entering[j] != 0);
        while(number[j] != 0 && number[j] < number[i] || (number[j] == number[i] && j < i));
    }

    sleep(1);
}


void exit_critical_section(int i)
{
    number[i] = 0;
}


void reserve_memory(int argc, char *argv[])
{
    check_input(argc, argv);

    mem_id = shmget(IPC_PRIVATE, sizeof(int) * (2 * num_of_processes + 1), 0600);
    if (mem_id == -1)
    {
        std::cout << "Nema zajednicke memorije!" << std::endl;
        exit(1);
    }
    else
    {
        memory = static_cast<int *>(shmat(mem_id, NULL, 0));
        entering = memory;
        number = memory + num_of_processes;
        A = number + num_of_processes;
    }

}


void free_mem(int sig)
{
    (void) shmdt((char *) entering);
    (void) shmdt((char *) number);
    (void) shmdt((char *) A);
    (void) shmctl(mem_id, IPC_RMID, nullptr);
}


void initialize()
{
    for (int i = 0; i < num_of_processes; ++i)
    {
        number[i] = entering[i] = 0;
    }
}


int main(int argc, char *argv[])
{
    reserve_memory(argc, argv);
    initialize();

    for (int i = 0; i < num_of_processes; ++i)
    {
        switch(fork())
        {
            case -1:
                std::cout << "Ne mogu stvoriti novi proces!" << std::endl;
                exit(1);
            case 0:
                enter_critical_section(i);
                process(i);
                exit_critical_section(i);
                exit(0);

        }
    }

    for (int i = 0; i < num_of_processes; ++i)
    {
        wait(nullptr);
    }

    printf("A=%d\n", A[0]);
    free_mem(0);

}

