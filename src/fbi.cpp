#include "fbi.hpp"
using namespace std;
void fbi(vector<Process *> processes, int last_instant, int number_of_queues) {
  vector<queue<Process *>> rq;               // Vector of queues
  for (int i = 0; i < number_of_queues; i++) // We have ~5 queues
  {
    queue<Process *> q;
    rq.push_back(q);
  }

  int t = 0;
  char name_last = '0';
  bool nothing_arrived = true;
  while (t < last_instant) {
    while (nothing_arrived) {
      nothing_arrived = !check_arrived(processes, rq[0], t);
      if (nothing_arrived)
        t++;
    }
    int rqi =
        get_queue_index(rq, name_last); // Get the index of 1st non empty queue

    queue<Process *> *q = &rq[rqi];
    Process *p = q->front();
    name_last = p->name;
    p->status[t] = '*';
    p->remaining_time--;
    q->pop();
    t++;

    check_arrived(processes, rq[0], t);
    bool rq_empty = is_rq_empty(rq); // Taking the flag first
    int qu = (int)pow(2, rqi);
    while (p->remaining_time > 0 && --qu) {
      p->status[t] = '*';
      p->remaining_time--;
      t++;
      check_arrived(processes, rq[0], t);
    }
    if (p->remaining_time > 0) {
      push_in_rq(rq, p, rqi, rq_empty);
    } else {
      p->finish_time = t;
    }
  }
}
