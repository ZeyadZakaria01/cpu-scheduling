#ifndef process_hpp
#define process_hpp

class Process {
public:
  char name;
  int arrive_time;
  int service_time;
  int remaining_time;
  int finish_time;

  Process();
  Process(char name,int arrive_time,int service_time);
  float getNormTurn();
  int getTurnAround();
};

#endif
