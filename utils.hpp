#ifndef utils_hpp
#define utils_hpp
#include "process.hpp"

bool check_arrived(std::vector<Process *> processes, std::queue<Process *> &q, int t);

bool is_rq_empty(std::vector<std::queue<Process *>> &rq);

int get_queue_index(std::vector<std::queue<Process *>> &rq,char);

int get_queue_index1(std::vector<std::queue<Process *>> &rq,char);

void push_in_rq(std::vector<std::queue<Process *>> &rq, Process *p, int rqi, bool rq_empty);

#endif
