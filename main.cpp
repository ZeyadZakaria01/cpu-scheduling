#include "fcfs.hpp"
#include "process.hpp"
#include "rr.hpp"
#include "tracehandler.hpp"

using namespace std;

void do_scheduling(string str, vector<Process *> processes, int last_instant) {
  TraceHandler *tc = new TraceHandler(last_instant);

  std::replace(str.begin(), str.end(), ',', ' ');
  vector<string> array;
  stringstream ss(str);
  string q_policy;

  while (ss >> q_policy) {
    int policy;
    int quantum;
    std::replace(q_policy.begin(), q_policy.end(), '-', ' ');
    // vector<string> my_array;
    stringstream my_ss(q_policy);
    string temp;
    bool is_policy = true;
    while (my_ss >> temp) {
      if (is_policy) {
        policy = stoi(temp);
        is_policy = false;
      } else {
        quantum = stoi(temp);
      }
    }
    switch (policy) {
    case 1: {
      first_come_first_serve(processes);
      tc->print_trace(processes, "FCFS");
      break;
    }
    case 2: {
      rr_serve(processes, quantum, last_instant);
      tc->print_trace(processes, "RR");
      break;
    }
    case 3: {
      tc->print_trace(processes, "SPN");
      break;
    }
    case 4: {
      tc->print_trace(processes, "SRT");
      break;
    }
    case 5: {
      tc->print_trace(processes, "HRRN");
      break;
    }
    case 6: {
      tc->print_trace(processes, "FB-1");
      break;
    }
    case 7: {
      tc->print_trace(processes, "FB-2i");
      break;
    }
    case 8: {
      tc->print_trace(processes, "Aging");
      break;
    }
    default: {
      cout << "Random value I guess? :D";
    }
    }
  }
}

int main() {
  vector<string> vc(4);
  for (int i = 0; i < 4; i++) {
    cin >> vc[i];
  }
  string mode = vc[0];
  string policy = vc[1];
  int last_instant = stoi(vc[2]);
  int number_of_processes = stoi(vc[3]);
  vector<Process *> processes;
  for (int i = 0; i < number_of_processes; i++) {
    string str;
    cin >> str;
    std::replace(str.begin(), str.end(), ',', ' '); // replace ',' by ' '
    vector<string> array;
    stringstream ss(str);
    string temp;
    while (ss >> temp)
      array.push_back(temp);
    Process *p =
        new Process(array[0][0], stoi(array[1]), stoi(array[2]), last_instant);
    processes.push_back(p);
  }
  cout << "mode: " << mode << endl;
  cout << "policy: " << policy << endl;
  printf("last_instant: %d\nnumber_of_processes:%d\n", last_instant,
         number_of_processes);
  for (int i = 0; i < number_of_processes; i++) {
    printf("%c,%d,%d\n", processes[i]->name, processes[i]->arrive_time,
           processes[i]->service_time);
  }
  do_scheduling(policy, processes, last_instant);

  return 0;
}
