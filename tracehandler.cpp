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
  cout << "------------------------------------------------";
  //
  for (Process *p : simulation) {
    int t = this->last_instances;
    cout << p->name << "     ";
    for (char ch : p->status) {
      cout << "|";
      if (p->arrive_time > t && ch != '*') {
        cout << ".";
      } else {
        cout << ch;
      }
      cout << "|";
    }
    cout << "\n"; // TODO:maybe better to flush to use endl
  }

  cout << "------------------------------------------------";
}

int main() {
  vector<Process *> simulation;
  string mode = "FCFS";
  int last_instances = 20;
  int n = 5;
  for (int i = 0; i < 5; i++) {
    char ch;
    int x, y;
    Process *p = new Process(ch, x, y, last_instances);
    simulation.push_back(p);
  }
  first_come_first_serve(simulation);
  TraceHandler *tc = new TraceHandler(last_instances);
  tc->print_trace(simulation, mode);
}
