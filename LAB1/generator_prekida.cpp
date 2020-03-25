#include <csignal>
#include <cstdio>
#include <iostream>
#include <zconf.h>
#include <cstdlib>

#define SLEEPY_TIME (rand() % (5 - 3) + 3)
#define RAND_SIGNAL (rand() % 4)

static int pid = 0;


void prekidna_rutina(int sig)
{
    kill(pid, SIGKILL);
    exit(0);
}

int main(int argc, char *argv[])
{
    pid = atoi(argv[1]);
    sigset(SIGINT, prekidna_rutina);

    srand(time(NULL));

    while(true)
    {
        sleep(SLEEPY_TIME);
        int signal = RAND_SIGNAL;

        switch (signal)
        {
            case(1):
                kill(pid, SIGUSR1);
                break;
            case(2):
                kill(pid,SIGUSR2);
                break;
            case(3):
                kill(pid, SIGALRM);
                break;
            case(4):
                kill(pid, SIGTRAP);
                break;

        }
    }
}

