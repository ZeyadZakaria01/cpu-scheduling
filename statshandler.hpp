
#ifndef statshandler_hpp
#define statshandler_hpp

#include "process.hpp"

class StatsHandler {
public:
  std::vector<Process *> simulation;
  int last_instances;

  StatsHandler(int last_instances);
  void output(std::vector<Process *> simulation, std::string mode);
};
#endif
