#include "tracehandler.hpp"
#include "fcfs.hpp"
#include "process.hpp"
#include <cstdio>
#include <vector>

using namespace std;

TraceHandler::TraceHandler(int last_instances) {
  this->last_instances = last_instances;
}

void TraceHandler::print_trace(std::vector<Process *> simulation, string mode) {
  // first row
  cout << mode << "  ";
  for (int i = 0; i < this->last_instances; i++) {
    cout << i % 10 << " ";
  }
  // second row
  cout << "\n------------------------------------------------\n";
  //
  for (Process *p : simulation) {
    int t = 0;
    int r = p->service_time;
    cout << p->name << "     ";
    for (char ch : p->status) {
      cout << "|";
      if (p->arrive_time <= t && ch != '*' ) {
        cout << ".";
      } else {
        cout << ch;
      }
      t++;
    }
      cout << "|";
    cout << "\n"; // TODO:maybe better to flush to use endl
  }

  cout << "------------------------------------------------\n";
}