#ifndef process_hpp
#define process_hpp
#include <bits/stdc++.h>

class Process {
public:
  char name;
  int arrive_time;
  int service_time;
  int remaining_time;
  int finish_time;
  int waiting_time;
  std::vector<char> status;

  Process();
  Process(char name, int arrive_time, int service_time,int last_instant);
  Process(char name, int arrive_time, int service_time,int last_instant,int waiting_time);
  float getNormTurn();
  int getTurnAround();
};

#endif
