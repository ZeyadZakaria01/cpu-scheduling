#ifndef handler_hpp
#define handler_hpp

#include "process.hpp"

class Handler {
public:
  int last_instances;

  Handler(int last_instances);
  virtual void output(std::vector<Process *> simulation, std::string mode);
};

#endif
