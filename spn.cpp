#include "spn.hpp"
#include "process.hpp"

bool spn_priority(Process *p1, Process *p2)
{
	int t1 = p1->service_time;
	int t2 = p2->service_time;
	return t1 > t2;
}

void shortest_process_next(std::vector<Process *> processes, int last_instant)
{
	using namespace std;
	int t = 0;
	priority_queue<Process *, vector<Process *>,
				   function<bool(Process *, Process *)>>
		pq(spn_priority);

	while (t < last_instant)
	{
		for (Process *p : processes)
		{
			if (p->arrive_time == t)
			{
				pq.push(p);
			}
		}
		if (pq.empty())
		{
			t++;
			continue;
		}
		Process *p = pq.top();
		pq.pop();
		while (p->remaining_time != 0)
		{
			for (Process *ptmp : processes)
			{
				if (ptmp->arrive_time == t && ptmp->name != p->name)
				{
					pq.push(ptmp);
				}
			}
			p->remaining_time--;
			p->status[t] = '*';
			t++;
		}
		if (p->remaining_time == 0)
		{
			p->finish_time = t;
		}
	}
}
