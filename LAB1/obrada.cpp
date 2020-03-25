#include <csignal>
#include <iostream>
#include <zconf.h>
#include <string>

#define N 6

static int OZNAKA_CEKANJA[N];
static int PRIORITET[N];
static int TEKUCI_PRIORITET;

static int sig[] = {SIGUSR1, SIGUSR2, SIGALRM, SIGTRAP, SIGINT};
void prekidna_rutina(int sig);

void postavi_obradu()
{
    sigset (SIGUSR1, prekidna_rutina);
    sigset (SIGUSR2, prekidna_rutina);
    sigset (SIGALRM, prekidna_rutina);
    sigset (SIGTRAP, prekidna_rutina);
    sigset (SIGINT, prekidna_rutina);
}


void zabrani_prekidanje()
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        sighold(sig[i]);
    }
}


void dozvoli_prekidanje()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        sigrelse(sig[i]);
    }
}

void ispisi_sekunde (int n, int sec)
{
    for (int brojac_sekundi = 1; brojac_sekundi <= sec; ++brojac_sekundi)
    {
        sleep(1);
        switch(n)
        {
            case(0):
                std::cout << std::to_string(brojac_sekundi).back() << "  -  -  -  -  -" << std::endl;
                break;
            case (1):
                std::cout << "-  " << brojac_sekundi << "  -  -  -  -" << std::endl;
                break;
            case (2):
                std::cout << "-  -  " << brojac_sekundi << "  -  -  -" << std::endl;
                break;
            case (3):
                std::cout << "-  -  -  " << brojac_sekundi << "  -  -" << std::endl;
                break;
            case (4):
                std::cout << "-  -  -  -  " << brojac_sekundi << "  -" << std::endl;
                break;
            case (5):
                std::cout << "-  -  -  -  -  " << brojac_sekundi << std::endl;
                break;
            default: std::cout << "ERROR" << std::endl;
        }
    }
}


void obrada_signala(int n)
{
    postavi_obradu();

    switch(n)
    {
        case (1):
            sleep(1);
            std::cout << "-  P  -  -  -  -" << std::endl;
            ispisi_sekunde(1, 5);
            sleep(1);
            std::cout << "-  K  -  -  -  -" << std::endl;
            break;
        case (2):
            sleep(1);
            std::cout << "-  -  P  -  -  -" << std::endl;
            ispisi_sekunde(2, 5);
            sleep(1);
            std::cout << "-  -  K  -  -  -" << std::endl;
            break;
        case (3):
            sleep(1);
            std::cout << "-  -  -  P  -  -" << std::endl;
            ispisi_sekunde(3, 5);
            sleep(1);
            std::cout << "-  -  -  K  -  -" << std::endl;
            break;
        case (4):
            sleep(1);
            std::cout << "-  -  -  -  P  -" << std::endl;
            ispisi_sekunde(4, 5);
            sleep(1);
            std::cout << "-  -  -  -  K  -" << std::endl;
            break;
        case (5):
            sleep(1);
            std::cout << "-  -  -  -  -  P" << std::endl;
            ispisi_sekunde(5, 5);
            sleep(1);
            std::cout << "-  -  -  -  -  K" << std::endl;
            return;
        default:
            sleep(1);
            std::cout << "ERROR" << std::endl;
    }
}


void prekidna_rutina(int sig)
{
    int n = -1;

    zabrani_prekidanje();

    switch(sig)
    {
        case SIGUSR1:
            n = 1;
            std::cout << ("-  X  -  -  -  -") << std::endl;
            break;
        case SIGUSR2:
            n = 2;
            std::cout << ("-  -  X  -  -  -") << std::endl;
            break;
        case SIGALRM:
            n = 3;
            std::cout << ("-  -  -  X  -  -") << std::endl;
            break;
        case SIGTRAP:
            n = 4;
            std::cout << ("-  -  -  -  X  -") << std::endl;
            break;
        case SIGINT:
            n = 5;
            std::cout << ("-  -  -  -  -  X") << std::endl;
            break;
        default:
            std::cout << "ERROR" << std::endl;
    }

    OZNAKA_CEKANJA[n] = 1;

    if (TEKUCI_PRIORITET < n) {
        int x;

        do {
            x = 0;

            for (int j = TEKUCI_PRIORITET + 1; j < N; j++)
            {
                if (OZNAKA_CEKANJA[j] == 1)
                    x = j;
            }

            if (x > 0)
            {
                OZNAKA_CEKANJA[x] = 0;
                PRIORITET[x] = TEKUCI_PRIORITET;
                TEKUCI_PRIORITET = x;
                dozvoli_prekidanje();
                obrada_signala(x);
                zabrani_prekidanje();
                TEKUCI_PRIORITET = PRIORITET[x];
            }
        } while (x > 0);

    }
    dozvoli_prekidanje();
}

int main(void)
{

    postavi_obradu();

    std::cout << "Proces obrade prekida, PID=" << getpid() << std::endl;

    std::cout << "G  1  2  3  4  5" << std::endl;
    std::cout << "-----------------" << std::endl;
    ispisi_sekunde(0, 20);
    std::cout << "Zavrsio osnovni program" << std::endl;
}