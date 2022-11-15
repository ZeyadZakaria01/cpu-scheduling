#include "fb1.hpp"
#include "fbi.hpp"
#include "fcfs.hpp"
#include "hrrn.hpp"
#include "process.hpp"
#include "rr.hpp"
#include "spn.hpp"
#include "srt.hpp"
#include "statshandler.hpp"
#include "tracehandler.hpp"
#include "utils.hpp"
#include <ostream>

using namespace std;

vector<Process *> deep_copy(vector<Process *> vc) {
  vector<Process *> new_vc;
  for (auto p : vc) {
    Process *p_tmp =
        new Process(p->name, p->arrive_time, p->service_time, p->status.size());
    new_vc.push_back(p_tmp);
  }
  return new_vc;
}

void do_scheduling_trace(string str, vector<Process *> processes,
                         int last_instant) {
  TraceHandler *handler = new TraceHandler(last_instant);

  std::replace(str.begin(), str.end(), ',', ' ');
  vector<string> array;
  stringstream ss(str);
  string q_policy;
  while (ss >> q_policy) {
    vector<Process *> p_copy = deep_copy(processes);

    int policy;
    int quantum;
    std::replace(q_policy.begin(), q_policy.end(), '-', ' ');
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
      first_come_first_serve(p_copy);
      handler->output(p_copy, "FCFS");
      break;
    }
    case 2: {
      rr_serve(p_copy, quantum, last_instant);
      string str = "RR-" + to_string(quantum);
      handler->output(p_copy, str);
      break;
    }
    case 3: {
      shortest_process_next(p_copy, last_instant);
      handler->output(p_copy, "SPN");
      break;
    }
    case 4: {
      srt(p_copy, last_instant);
      handler->output(p_copy, "SRT");
      break;
    }
    case 5: {
      hrrn(p_copy, last_instant);
      handler->output(p_copy, "HRRN");
      break;
    }
    case 6: {
      fb1(p_copy, last_instant, p_copy.size());
      handler->output(p_copy, "FB-1");
      break;
    }
    case 7: {
      fbi(p_copy, last_instant, p_copy.size());
      handler->output(p_copy, "FB-2i");
      break;
    }
    case 8: {
      handler->output(p_copy, "Aging");
      break;
    }
    default:
      cout << "Random value I guess? :D";
    }
  }
}

void do_scheduling_stats(string str, vector<Process *> processes,
                         int last_instant) {

  StatsHandler *handler = new StatsHandler(last_instant);

  std::replace(str.begin(), str.end(), ',', ' ');
  vector<string> array;
  stringstream ss(str);
  string q_policy;
  while (ss >> q_policy) {
    vector<Process *> p_copy = deep_copy(processes);
    // vector<Process *> p_copy = processes;

    int policy;
    int quantum;
    std::replace(q_policy.begin(), q_policy.end(), '-', ' ');
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
      first_come_first_serve(p_copy);
      handler->output(p_copy, "FCFS");
      break;
    }
    case 2: {
      rr_serve(p_copy, quantum, last_instant);
      string str = "RR-" + to_string(quantum);
      handler->output(p_copy, str);
      break;
    }
    case 3: {
      shortest_process_next(p_copy, last_instant);
      handler->output(p_copy, "SPN");
      break;
    }
    case 4: {
      srt(p_copy, last_instant);
      handler->output(p_copy, "SRT");
      break;
    }
    case 5: {
      hrrn(p_copy, last_instant);
      handler->output(p_copy, "HRRN");
      break;
    }
    case 6: {
      fb1(p_copy, last_instant, p_copy.size());
      handler->output(p_copy, "FB-1");
      break;
    }
    case 7: {
      fbi(p_copy, last_instant, p_copy.size());
      handler->output(p_copy, "FB-2i");
      break;
    }
    case 8: {
      handler->output(p_copy, "Aging");
      break;
    }
    default:
      cout << "Random value I guess? :D";
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
  /* cout << "mode: " << mode << endl; */
  /* cout << "policy: " << policy << endl; */
  /* printf("last_instant: %d\nnumber_of_processes:%d\n", last_instant, */
  /*        number_of_processes); */
  /* for (int i = 0; i < number_of_processes; i++) { */
  /*   printf("%c,%d,%d\n", processes[i]->name, processes[i]->arrive_time, */
  /*          processes[i]->service_time); */
  /* } */
  if (policy == "aging") {
    for (int i = 0; i < number_of_processes; i++)
      processes[i]->priority = processes[i]->service_time;
  }
  mode == "stats" ? do_scheduling_stats(policy, processes, last_instant)
                  : do_scheduling_trace(policy, processes, last_instant);

  return 0;
}
