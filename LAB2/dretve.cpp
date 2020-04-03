#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <zconf.h>

#define MAXTHREAD 20
#define MAXTIMES 1000000

static int num_of_threads;
static int times_add;
static int A;


void *thread(void *id)
{

        for (int i = 0; i < times_add; ++i)
        {
            int *d = static_cast<int *>(id);

            printf ("Dretva %d; iteracija=%d\n", *d, i+1);
            A += 1;
            sleep(1);
        }
}


void check_input(int argc, char *argv[])
{
    if (argc != 3 || std::atoi(argv[1]) > MAXTHREAD || std::atoi(argv[2]) > MAXTIMES)
    {
        std::cout << "Krivi argumenti. Dodaj <INT> broj dretvi do " << MAXTHREAD << " i <INT> broj ponavljanja do " << MAXTIMES << std::endl;
        exit(1);
    }
    else
    {
        num_of_threads = std::atoi(argv[1]);
        times_add = std::atoi(argv[2]);
    }
}


int main(int argc, char *argv[])
{

    check_input(argc, argv);
    A = 0;

    int BR[num_of_threads];
    pthread_t t[num_of_threads];

    for (int i = 0; i < num_of_threads; ++i)
    {
        BR[i] = i;
        if (pthread_create(&t[i], nullptr, thread, &BR[i]))
        {
            std::cout << "Ne mogu stvoriti dretvu br." << BR[i] << "!" << std::endl;
            exit(1);
        }
    }

    for (int i = 0; i < num_of_threads; ++i)
        pthread_join(t[i], nullptr);

    std::cout << "A=" << A << std::endl;
}

