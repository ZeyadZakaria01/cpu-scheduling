#ifndef tracehandler_hpp
#define tracehandler_hpp

#include "process.hpp"

class TraceHandler {
public:
  std::vector<Process *> simulation;
  int last_instances;

  TraceHandler(int last_instances);
  void print_trace(std::vector<Process *> simulation, std::string mode);
};
#endif
