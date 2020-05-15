#include <iostream>
#include <deque>
#include <algorithm>
#include <zconf.h>


constexpr int THREADS = 6;
constexpr int MAX_WAITING_THREADS = 5;
constexpr int DETAILS = 5;

static int to_be_finished_threads = THREADS; //broj preostalih dretvi
static int filled = 0; //popunjena mjesta u redu pripravnih dretvi

static bool header = true;
static int current_time = 0;
static int  thread_details[THREADS][DETAILS] =
        {   {1, 3, 5, 3, 1},
            {3, 5, 6, 5, 1},
            {7, 2, 3, 5, 1},
            {12, 1, 5, 3, 0},
            {20, 6, 3, 6, 1},
            {20, 7, 4, 7, 1},
        };

static int quant = 1;

class Thread
{
public:
    int i;
    int id;
    int coming_time;
    int time_left;
    int priority;
    int scheduling;


    explicit Thread(int t_i) : i(t_i)
    {
        coming_time = thread_details[i][0];
        id = thread_details[i][1];
        time_left = thread_details[i][2];
        priority = thread_details[i][3];
        scheduling = thread_details[i][4];
    }
};


static std::deque<Thread> ready_threads;    //red pripravnih
static std::deque<Thread> all_threads;      //zadane dretve


void init()
{
    for (int i = 0; i < THREADS; ++i)
    {
        all_threads.push_back(Thread(i));
    }
}


void output()
{
    if(header)
    {
        std::cout << "  t    AKT";
        for (int i = 1; i < MAX_WAITING_THREADS; ++i)
        {
            std::cout << "     PR" << i;
        }
        std::cout << "\n";
        header = false;
    }

    printf("%3d ", current_time);

    for(auto &ready_thread : ready_threads)
    {
        Thread *thread = &ready_thread;
        printf("  %d/%d/%d ", thread->id, thread->priority, thread->time_left);
    }

    if (ready_threads.size() < MAX_WAITING_THREADS)
    {
        int i = ready_threads.size();
        while (i < MAX_WAITING_THREADS)
        {
            printf("  -/-/- ");
            ++i;
        }
    }

    std::cout << "\n";
}


void check_ending()
{
    if (ready_threads.begin()->time_left == 0) //ako dretva zavrsava
    {
        printf("%3d -- zavrsava dretva id=%d, p=%d, prio=%d\n", current_time,
               ready_threads.at(0).id, ready_threads.at(0).time_left, ready_threads.at(0).priority);

        ready_threads.pop_front();

        to_be_finished_threads--;
        filled--;
    }
}


void PRIORITY()
{
    ready_threads.begin()->time_left -= 1;
    check_ending();

}


void FIFO()
{
    ready_threads.begin()->time_left -= 1;
    check_ending();
}


void RR()
{
    if (!ready_threads.empty())
    {

        if (ready_threads.size() <= MAX_WAITING_THREADS) //provjeri jel u redu pripravnih ima jos mjesta
         {
            ready_threads.begin()->time_left -= quant;
            ready_threads.push_back(ready_threads.at(0));
            ready_threads.pop_front();
         }

        check_ending();
    }
}


void add_new_thread(Thread &thread)
{
    ready_threads.push_back(thread);
    printf("%3d -- nova dretva id=%d, p=%d, prio=%d, %s\n", current_time, thread.id,
           thread.time_left, thread.priority, thread.scheduling == 1 ? "PRIO+FIFO" : "PRIO+RR");
    filled++;
}


void schedule()
{

    output();

    std::deque<Thread> waiting_threads; //dretve koje ne stanu u red pripravnih dretvi

    while(to_be_finished_threads > 0)
    {

        for (Thread &thread : all_threads)
        {
            if (thread.coming_time == current_time) //dretva pocinje s radom
            {
                if (ready_threads.size() < MAX_WAITING_THREADS) //ako jos ima mjesta u redu pripravnih
                {
                   add_new_thread(thread);

                    if(! waiting_threads.empty())
                    {
                        add_new_thread(waiting_threads.at(0));
                        waiting_threads.pop_front();
                    }
                }
                else
                    waiting_threads.push_back(thread);
            }
        }

        if (!ready_threads.empty())
        {
            std::sort(ready_threads.begin(), ready_threads.end(), [](const auto& a, const auto& b)
                        { return a.priority > b.priority; });

            output();

            if (ready_threads.size() > 1 && (ready_threads.at(0).priority == ready_threads.at(1).priority))
            {   //provjeri na koji nacin je zadano rasporedivanje dretvi ako ima vise jednakih prioriteta
                ready_threads.at(1).scheduling == 1 ? FIFO() : RR();
            }
            else
            {
                PRIORITY();
            }
        }

        //sleep(1);
        current_time++;
    }
}


int main()
{
    init();
    schedule();
}

