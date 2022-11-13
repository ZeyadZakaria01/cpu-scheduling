#include "fb1.hpp"
using namespace std;

void fb1(vector<Process *> processes, int last_instant, int number_of_queues)
{
    vector<queue<Process *>> rq;               // Vector of queues
    for (int i = 0; i < number_of_queues; i++) // We have ~5 queues
    {
        queue<Process *> q;
        rq.push_back(q);
    }

    int t = 0;
    bool nothing_arrived = true;
    while (t < last_instant)
    {
        while (nothing_arrived)
        {
            nothing_arrived = !check_arrived(processes, rq[0], t);
            if (nothing_arrived)
                t++;
        }
        int rqi = get_queue_index(rq); // Get the index of 1st non empty queue
        queue<Process *> *q = &rq[rqi];
        Process *p = q->front();
        p->status[t] = '*';
        p->remaining_time--;
        q->pop();
        t++;
        bool rq_empty = is_rq_empty(rq); // Taking the flag first
        check_arrived(processes, rq[0], t);
        if (p->remaining_time > 0)
            push_in_rq(rq, p, rqi, rq_empty);
        else
        {
            p->finish_time = t;
        }
    }
}
