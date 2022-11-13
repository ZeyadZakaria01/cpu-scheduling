#include "utils.hpp"
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
bool is_rq_empty(std::vector<std::queue<Process *>> &rq)
{
    for (auto &x : rq)
    {
        if (!x.empty())
        {
            return false;
        }
    }
    return true;
}
int get_queue_index(std::vector<std::queue<Process *>> &rq)
{
    int rqi = 0;
    for (auto &q : rq)
    {
        if (!q.empty())
        {
            return rqi;
        }
        rqi++;
    }
    return -1;
}
void push_in_rq(std::vector<std::queue<Process *>> &rq, Process *p, int rqi, bool rq_empty)
{
    if (rq_empty || rqi == rq.size() - 1)
    {
        rq[rqi].push(p);
    }
    else
    {
        rq[rqi + 1].push(p);
    }
}