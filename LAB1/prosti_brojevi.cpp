#include <iostream>
#include <csignal>
#include <cstdio>
#include <sys/time.h>
#include <cmath>
#include <zconf.h>
#include <algorithm>


static unsigned long current_number = 10000001;
static unsigned long last_number = 10000001;
static bool sigint_flag = false;


bool is_prime(unsigned long current_number)
{
    if (((current_number > 2 && current_number % 2) == 0) || current_number == 0 || current_number == 1)
        return false;

    unsigned long max = floor(sqrt(current_number));

    for (unsigned long i = 2; i <= max; i += 2)
    {
        if ((current_number % i) == 0)
            return false;
    }
    return true;
}


void print_prime(int sig)
{
    std::cout << "Zadnji prosti broj = " << last_number << "\n";
}

void stopper(int sig)
{
    print_prime(sig);
    exit(0);
}


void change_state(int sig)
{
    sigint_flag = !sigint_flag;
}


int main()
{
    struct itimerval t;

    sigset(SIGALRM, print_prime);
    sigset(SIGQUIT, stopper);
    sigset(SIGINT, change_state);


    t.it_value.tv_sec = 0;
    t.it_value.tv_usec = 500000;

    t.it_interval.tv_sec = 0;
   t.it_interval.tv_usec = 500000;

    setitimer ( ITIMER_REAL, &t, NULL );


    while(true) {
        if(is_prime(current_number))
            last_number = current_number;

        current_number++;

        while(sigint_flag) {
            pause();
        }
    }
}

