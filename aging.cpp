#include "aging.hpp"

using namespace std;
void update_pq(priority_queue<Process *, vector<Process *>, function<bool(Process *, Process *)>> &pq)
{
	vector<Process *> waiting_in_pq;
	while (!pq.empty())
	{
		Process *p_waiting = pq.top();
		pq.pop();
		p_waiting->priority++;
		waiting_in_pq.push_back(p_waiting);
	}
	for (Process *p : waiting_in_pq)
	{
		// cout << "updating,process name: " << p->name << ", p->priority:" << p->priority << endl;
		pq.push(p);
	}
}
bool push_arrived(priority_queue<Process *, vector<Process *>, function<bool(Process *, Process *)>> &pq, vector<Process *> processes, int t)
{
	bool arrived = false;
	for (Process *p : processes)
	{
		if (p->arrive_time == t)
		{
			pq.push(p);
			arrived = true;
			// cout << "pushing on arrive,process name: " << p->name << ", p->priority:" << p->priority << endl;
		}
	}
	return true;
}
bool aging_priority(Process *p1, Process *p2)
{
	int prio1 = p1->priority, prio2 = p2->priority;
	if (prio1 == prio2)
		return p1->arrive_time > p2->arrive_time;
	return p1 < p2;
}
void aging(vector<Process *> processes, int quantum, int last_instant)
{
	priority_queue<Process *, vector<Process *>,
				   function<bool(Process *, Process *)>>
		pq(aging_priority);

	unordered_map<char, int> original_priorities;
	for (Process *p : processes)
	{
		p->priority = p->service_time;
		original_priorities[p->name] = p->priority;
	}

	int t = 0;
	bool nothing_arrived = true;
	// cout << "time =" << t << endl;
	while (t < last_instant)
	{
		if (nothing_arrived)
		{
			nothing_arrived = !push_arrived(pq, processes, t);
			update_pq(pq);
		}
		if (pq.empty())
		{
			t++;
			continue;
		}
		Process *p = pq.top();
		pq.pop();
		int qu = quantum;
		while (qu-- && t < last_instant)
		{
			p->status[t] = '*';
			t++;
			// cout << "time =" << t << endl;
			push_arrived(pq, processes, t);
		}
		update_pq(pq);
		p->priority = original_priorities[p->name];
		// cout << "After excution, p->name=" << p->name << ",p->priority=" << p->priority << endl << endl;
		pq.push(p);
	}
}
