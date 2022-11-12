#include "srt.hpp"
bool srt_priority(Process *p1, Process *p2)
{
    int t1 = p1->remaining_time;
    int t2 = p2->remaining_time;
    return t1 > t2;
}
void srt(std::vector<Process *> processes, int last_instant)
{
    using namespace std;
    int t = 0;
    priority_queue<Process *, vector<Process *>,
                   function<bool(Process *, Process *)>>
        pq(srt_priority);
    while (t < last_instant)
    {
        if (!pq.empty())
        {
            Process *p = pq.top();
            pq.pop();
            p->remaining_time--;
            p->status[t] = '*';

            if (p->remaining_time > 0)
                pq.push(p);
            t++;
        }
        for (Process *p : processes)
        {
            bool flag_push = false;
            Process *ptemp;
            if (!pq.empty())
            {
                ptemp = pq.top();
                pq.pop();
                flag_push = true;
            }
            if (p->arrive_time == t)
            {
                cout << p->name << endl;
                pq.push(p);
            }
            if (flag_push)
            {
                pq.push(ptemp);
            }
        }
        if (pq.empty())
        {
            t++;
            continue;
        }
    }
}