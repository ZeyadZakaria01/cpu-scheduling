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
  std::vector<char> status;

  Process();
  Process(char name, int arrive_time, int service_time,int last_instant);
  float getNormTurn();
  int getTurnAround();
};

#endif
