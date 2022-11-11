#include "rr.hpp"

void rr_serve(std::vector<Process *> processes, int quantum, int last_instant)
{
    using namespace std;
    int t = 0;
    cout << "In RR\n";
    queue<Process *> q;
    for (Process *p : processes)
    {
        if (p->arrive_time == 0)
            q.push(p);
    }
    while (t < last_instant)
    {

        Process *p = q.front();
        q.pop();
        p->status[t] = '*';
        p->remaining_time--;
        t++;
        for (Process *p : processes)
        {
            if (t == p->arrive_time)
                q.push(p);
            else if (t < p->arrive_time)
                break;
        }
        if (p->remaining_time > 0)
        {
            q.push(p);
        }
    }
    for (Process *p : processes)
    {
        std::cout << p->name << "\t";
        std::cout << "|";
        for (char x : p->status)
            std::cout << x << "|";
        cout << endl;
    }

    std::cout << std::endl;
}
