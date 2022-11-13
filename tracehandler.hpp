#include "process.hpp"

#ifndef tracehandler_hpp
#define tracehandler_hpp

class TraceHandler {
public:
  int last_instances;
  TraceHandler(int last_instances);
  void output(std::vector<Process *> simulation, std::string mode);
};
#endif
