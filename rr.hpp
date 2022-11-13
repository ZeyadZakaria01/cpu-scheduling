#ifndef rr_hpp
#define rr_hpp

#include "process.hpp"

bool check_arrived(std::vector<Process *> processes, std::queue<Process *> &q, int t);
void rr_serve(std::vector<Process *> processes, int quantum, int last_instant);

#endif
