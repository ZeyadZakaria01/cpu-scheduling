#define FOR for (Process * p : simulation)

#include "statshandler.hpp"

using namespace std;

StatsHandler::StatsHandler(int last_instances) {
  this->last_instances = last_instances;
}

void StatsHandler::output(vector<Process *> simulation, string mode) {

  float sum_turn_around = 0;
  float sum_norm_turn = 0;
  cout << mode << endl;
  cout << "Process    ";
  for (Process *p : simulation) {
    printf("| %2c  ", p->name);
  }
  cout << "|";
  cout << endl;
  cout << "Arrival    ";
  for (Process *p : simulation) {
    printf("| %2d  ", p->arrive_time);
  }
  cout << "|";
  cout << endl;
  cout << "Service    ";
  for (Process *p : simulation) {
    printf("| %2d  ", p->service_time);
  }
  cout << "|";
  printf(" %2s", "Mean");
  cout << "|";
  cout << endl;
  cout << "Finish     ";
  for (Process *p : simulation) {
    printf("| %2d  ", p->finish_time);
  }
  cout << "|";
  for (int i = 0; i < 5; i++)
    cout << "-";
  cout << "|";
  cout << endl;
  cout << "Turnaround ";
  for (Process *p : simulation) {
    int turn_around = p->getTurnAround();
    printf("| %2d  ", turn_around);
    sum_turn_around += turn_around;
  }
  cout << "|";
  printf("%-.2f", sum_turn_around / (float)simulation.size());
  cout << "|";
  cout << endl;
  cout << "NormTurn   ";
  for (Process *p : simulation) {
    float norm_turn = p->getNormTurn();
    sum_norm_turn += norm_turn;
    printf("| %-.2f", norm_turn);
  }

  cout << "|";
  printf(" %-.2f", sum_norm_turn / (float)simulation.size());
  cout << "|";
  cout << endl;
}
