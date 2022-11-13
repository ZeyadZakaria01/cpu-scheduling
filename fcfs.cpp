#include "fcfs.hpp"
bool fcfs_sort(Process *p1, Process *p2) {
  int t1 = p1->arrive_time;
  int t2 = p2->arrive_time;

  return t1 < t2;
}

void first_come_first_serve(std::vector<Process *> processes) {
  using namespace std;
  int t = 0;
  queue<Process *> q;

  std::sort(processes.begin(), processes.end(), &fcfs_sort);

  for (Process *p : processes)
    q.push(p);

  while (!q.empty()) {
    Process *p = q.front();
    /* if (p->arrive_time < t) { */
    /*   t++; */
    /*   continue; */
    /* } */
    q.pop();
    while (p->remaining_time != 0) {
      p->remaining_time--;
      p->status[t] = '*';
      t++;
    }
    // useless condition
    if(p->remaining_time==0){
        p->finish_time = t;
    }
  }
  std::cout << std::endl;
}
