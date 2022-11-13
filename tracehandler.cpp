#include "tracehandler.hpp"

using namespace std;

TraceHandler::TraceHandler(int last_instances)
{
  this->last_instances = last_instances;
}

void TraceHandler::output(std::vector<Process *> simulation, string mode)
{
  int l = mode.length() + 4 + 2 * last_instances;
  // first row
  cout << mode << "  ";
  for (int i = 0; i < this->last_instances + 1; i++)
  {
    cout << i % 10 << " ";
  }
  // second row
  cout << endl;
  for (int i = 0; i < l; i++)
    cout << '-';
  cout << endl;
  for (Process *p : simulation)
  {
    int t = 0;
    int r = p->service_time;
    cout << p->name << "     ";
    for (char ch : p->status)
    {
      cout << "|";
      if (p->arrive_time <= t && ch != '*')
      {
        if (r <= 0)
        {
          cout << " ";
        }
        else
        {
          cout << ".";
        }
      }
      else
      {
        if (ch == '*')
          r--;
        cout << ch;
      }
      t++;
    }
    cout << "|";
    cout << "\n"; // TODO:maybe better to flush to use endl
  }

  // second row
  for (int i = 0; i < l; i++)
    cout << '-';
  cout << endl;
}
