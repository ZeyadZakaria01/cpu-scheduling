#include "tracehandler.hpp"

using namespace std;

TraceHandler::TraceHandler(int last_instances) {
  this->last_instances = last_instances;
}

void TraceHandler::output(std::vector<Process *> simulation, string mode) {
  int spaces_before_mode = 6;
  spaces_before_mode -= mode.length();
  /* int l = mode.length() + 4 + 2 * last_instances; */
  // first row
  cout << mode;
  for(int i = 0;i <spaces_before_mode;i++)
  {
      cout<<" ";
  }
  for (int i = 0; i < this->last_instances + 1; i++) {
    cout << i % 10 << " ";
  }
  /* cout << "\n"; */
  cout << endl;
  // second row
  // always 48
  for (int i = 0; i < 48; i++)
    cout << '-';
  /* cout << "\n"; */
  cout << endl;
  for (Process *p : simulation) {
    int t = 0;
    int r = p->service_time;
    cout << p->name << "     ";
    for (char ch : p->status) {
      cout << "|";
      if (p->arrive_time <= t && ch != '*') {
        if (r <= 0) {
          cout << " ";
        } else {
          cout << ".";
        }
      } else {
        if (ch == '*')
          r--;
        cout << ch;
      }
      t++;
    }
    cout << "| ";
    /* cout << "\n"; */
    cout << endl;
  }

  // second row
  for (int i = 0; i < 48; i++)
    cout << '-';
  cout << endl;
  cout << endl;
}
