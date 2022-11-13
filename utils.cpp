#include "utils.hpp"
bool check_arrived(std::vector<Process *> processes, std::queue<Process *> &q,
                   int t) {
  bool flag = false;
  for (Process *p : processes) {
    if (p->arrive_time == t) {
      q.push(p);
      flag = true;
    }
  }
  return flag;
}
bool is_rq_empty(std::vector<std::queue<Process *>> &rq) {
  for (auto &x : rq) {
    if (!x.empty()) {
      return false;
    }
  }
  return true;
}
int get_queue_index(std::vector<std::queue<Process *>> &rq, char last_name) {
    using namespace std;
  std::vector<std::pair<char, int>> idxs;
  int rqi = 0;
  for (int i = 0; i < rq.size(); i++) {
    if (!rq[i].empty()) {
      idxs.push_back({rq[i].front()->name, i});
    }
  }

  if (idxs.size() == 1 || last_name == idxs[idxs.size() - 1].first) {
    return idxs[0].second;
  } else {
    for (int i = 0; i < idxs.size(); i++) {
      if (last_name == idxs[i].first)
        return idxs[i + 1].second;
    }
  }
  return idxs[0].second;
}
void push_in_rq(std::vector<std::queue<Process *>> &rq, Process *p, int rqi,
                bool rq_empty) {
  if (rq_empty || rqi == rq.size() - 1) {
    rq[rqi].push(p);
  } else {
    rq[rqi + 1].push(p);
  }
}
