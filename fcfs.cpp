#include "fcfs.hpp"
bool fcfs_sort(Process const &p1, Process const &p2) {
  int t1 = p1.arrive_time;
  int t2 = p2.arrive_time;

  return t1 < t2;
}

void first_come_first_serve(std::vector<Process> processes) {
  std::queue<Process> q;

  std::sort(processes.begin(), processes.end(), &fcfs_sort);
  for (auto p : processes)
    q.push(p);
  while (!q.empty()) {
    Process p = q.front();
    q.pop();
  }

  std::cout << std::endl;
}
