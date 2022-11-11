#include "fcfs.hpp"
bool fcfs_sort(Process *p1, Process *p2) {
  int t1 = p1->arrive_time;
  int t2 = p2->arrive_time;

  return t1 < t2;
}

void first_come_first_serve(std::vector<Process *> processes) {
  using namespace std;
  int t = 0;
  cout << "In FCFS\n";
  cout << "hI";
  queue<Process *> q;

  std::sort(processes.begin(), processes.end(), &fcfs_sort);
  for (Process *p : processes)
    q.push(p);
  while (!q.empty()) {
    Process *p = q.front();
    q.pop();
    std::cout << "At Process" << p->name;
    while (p->remaining_time != 0) {
      p->remaining_time--;
      p->status[t] = '*';
      t++;
    }
    std::cout << p->status.size();
    for (char x : p->status)
      std::cout << x << " ";
    cout << endl;
  }

  std::cout << std::endl;
}
