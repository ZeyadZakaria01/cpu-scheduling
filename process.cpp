
#include "process.hpp"

Process::Process(char name, int arrive_time, int service_time,
                 int last_instant) {
  this->name = name;
  this->arrive_time = arrive_time;
  this->service_time = service_time;
  this->remaining_time = service_time;
  this->status = std::vector<char>(last_instant, ' ');
}

Process::Process() {}

int Process::getTurnAround() {

  int res = this->finish_time - this->arrive_time;
  return res;
}

float Process::getNormTurn() {
  return this->getTurnAround() / (float)this->service_time;
}
