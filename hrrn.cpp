#include "hrrn.hpp"
#include "process.hpp"
#include <complex>

int t;

bool hrrn_priority(Process *p1, Process *p2) {
  /* int w1 = t - p1->arrive_time - (p1->service_time - p1->remaining_time); */
  // 13 - 6 - ( 5 - 5) = 7
  /* int w2 = t - p2->arrive_time - (p2->service_time - p2->remaining_time); */
  // 13 - 8 - (2 - 2) = 5
  //
  int w1 = p1->waiting_time;
  int w2 = p2->waiting_time;
  // 7 +5 / 5 = 12 / 5 = 2.x
  //  5+ 2 / 5 = 7/5 =  1.x
  float r1 = (w1 + p1->service_time) / float(p1->service_time);
  float r2 = (w2 + p2->service_time) / float(p2->service_time);
  /* printf("at t3 = %d, %c-> %f, w1 = %d - %c-> %f, w2 = %d\n", t, p1->name,
   * r1, */
  /*        w1, p2->name, r2, w2); */

  return r1 < r2;
}
void hrrn(std::vector<Process *> processes, int last_instant) {
  using namespace std;
  t = 0;
  cout << "In HRRN\n";
  priority_queue<Process *, vector<Process *>,
                 function<bool(Process *, Process *)>>
      pq(hrrn_priority);

  while (t < last_instant) {

    for (Process *p : processes) {
      if (p->arrive_time == t) {
        pq.push(p);
      }
    }
    if (pq.empty()) {
      t++;
      continue;
    }
    Process *p = pq.top();
    pq.pop();
    while (p->remaining_time != 0) {
      for (Process *p : processes) {
        if (p->arrive_time == t) {
          pq.push(p);
        }
      }
      p->remaining_time--;
      p->status[t] = '*';
      if (p->remaining_time == 0) {
        p->finish_time = t;
      }
      vector<Process *> waiting_in_pq;
      while (!pq.empty()) {
        Process *p_waiting = pq.top();
        pq.pop();
        p_waiting->waiting_time++;
        waiting_in_pq.push_back(p_waiting);
      }
      for (Process *waiting_proces : waiting_in_pq)
        pq.push(waiting_proces);
    }
  t++;
  }
}
