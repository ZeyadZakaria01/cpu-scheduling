#include "rr.hpp"
bool check_arrived(std::vector<Process *> processes, std::queue<Process *> &q, int t)
{
    bool flag = false;
    for (Process *p : processes)
    {
        if (p->arrive_time == t)
        {
            q.push(p);
            flag = true;
        }
    }
    return flag;
}
void rr_serve(std::vector<Process *> processes, int quantum, int last_instant)
{
    using namespace std;
    int t = 0;
    queue<Process *> q;
    bool nothing_arrived = true;
    while (t < last_instant)
    {
        if (nothing_arrived)
            nothing_arrived = !check_arrived(processes, q, t);
        int st_time = t;
        Process *p = q.front();
        p->status[t] = '*';
        p->remaining_time--;
        q.pop();
        t++;
        check_arrived(processes, q, t);
        int qu = quantum;
        while (--qu && p->remaining_time > 0)
        {
            p->status[t] = '*';
            p->remaining_time--;
            t++;
            check_arrived(processes, q, t);
        }
        if (p->remaining_time > 0)
        {
            q.push(p);
        }
        else
        {
            p->finish_time = t;
        }
    }
}
