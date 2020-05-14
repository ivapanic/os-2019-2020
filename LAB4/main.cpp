#include <iostream>
#include <zconf.h>
#include <deque>

#define THREADS 6
#define MAX_WAITING_THREADS 5 //red pripravnih dretvi
#define DETAILS 4

static bool header = true;
static int current_time = 0;
static int  thread_details[THREADS][DETAILS] =
        {   {1, 3, 5, 3},
            {3, 5, 6, 5},
            {7, 2, 3, 5},
            {12, 1, 5, 3},
            {20, 6, 3, 6},
            {20, 7, 4, 7}
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

    explicit Thread(int t_i) : i(t_i)
    {
        coming_time = thread_details[i][0];
        id = thread_details[i][1];
        time_left = thread_details[i][2];
        priority = thread_details[i][3];
    }

};


static std::deque<Thread> ready_threads;
static std::deque<Thread> all_threads;


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



void RR()
{
    int to_be_finished_threads = THREADS;
    int seen_threads = 0;
    int filled = 0;

    std::deque<Thread> waiting_threads;


    while (to_be_finished_threads > 0)
    {

        if (!ready_threads.empty())
        {
            if (ready_threads.begin()->time_left == 0)
            {
                printf("  %d -- zavrsava dretva id=%d, p=%d, prio=%d\n", current_time,
                       ready_threads.at(0).id, ready_threads.at(0).time_left, ready_threads.at(0).priority);

                ready_threads.pop_front();

                to_be_finished_threads--;
                filled--;
            }

            else
            {
                if (ready_threads.size() == MAX_WAITING_THREADS)
                {
                    ready_threads.push_front(ready_threads.back());
                    ready_threads.pop_back();
                    ready_threads.begin()->time_left -= quant;
                }

                else
                {
                    if(!waiting_threads.empty())
                    {
                        ready_threads.push_front(waiting_threads.at(0));
                        printf("%3d -- nova dretva id=%d, p=%d, prio=%d\n", current_time, ready_threads.at(0).id,
                               ready_threads.at(0).time_left, ready_threads.at(0).priority);
                        waiting_threads.pop_front();
                    }
                    else
                    {
                        if (seen_threads == THREADS - 1)
                        {
                            ready_threads.push_front(ready_threads.back());
                            ready_threads.pop_back();
                            ready_threads.begin()->time_left -= quant;
                        }
                    }
                }
            }
        }

        for (auto &thread : all_threads)
        {
            if (thread.coming_time == current_time)
            {
                if (ready_threads.size() < MAX_WAITING_THREADS)
                {
                    ready_threads.push_front(thread);
                    printf("%3d -- nova dretva id=%d, p=%d, prio=%d\n", current_time, thread.id,
                           thread.time_left, thread.priority);
                    output();
                    filled++;
                    seen_threads++;
                    ready_threads.begin()->time_left -= quant;
                }

                else
                {

                    waiting_threads.push_back(thread);
                }

            }

        }

        output();
        //sleep(1);
        current_time++;
    }


}


int main()
{
    init();
    RR();

}
