#include "fcfs.hpp"
#include "rr.hpp"
#include "process.hpp"
#include <cwchar>
#include <vector>

using namespace std;

void do_scheduling(string str, vector<Process *> processes, int last_instant)
{
    // add forloop in case of more than one policy
    std::replace(str.begin(), str.end(), ',', ' ');
    vector<string> array;
    stringstream ss(str);
    string temp;
    while (ss >> temp)
    {
        int policy;
        int quantum;
        std::replace(temp.begin(), temp.end(), '-', ' ');
        // vector<string> my_array;
        stringstream my_ss(temp);
        string my_temp;
        bool my_flag = true;
        while (my_ss >> my_temp)
        {
            if (my_flag)
            {
                policy = stoi(my_temp);
                my_flag = false;
            }
            else
            {
                quantum = stoi(my_temp);
            }
        }
        switch (policy)
        {
        case 1:
        {
            first_come_first_serve(processes);
            break;
        }
        case 2:
        {
            rr_serve(processes, quantum, last_instant);
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            break;
        }
        default:
        {
            cout << "Random value I guess? :D";
        }
        }
    }
}

int main()
{
    vector<string> vc(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> vc[i];
    }
    string mode = vc[0];
    string policy = vc[1];
    int last_instant = stoi(vc[2]);
    int number_of_processes = stoi(vc[3]);
    vector<Process *> processes;
    for (int i = 0; i < number_of_processes; i++)
    {
        string str;
        cin >> str;
        std::replace(str.begin(), str.end(), ',', ' '); // replace ',' by ' '
        vector<string> array;
        stringstream ss(str);
        string temp;
        while (ss >> temp)
            array.push_back(temp);
        Process *p =
            new Process(array[0][0], stoi(array[1]), stoi(array[2]), last_instant);
        processes.push_back(p);
    }
    cout << "mode: " << mode << endl;
    cout << "policy: " << policy << endl;
    printf("last_instant: %d\nnumber_of_processes:%d\n", last_instant,
           number_of_processes);
    for (int i = 0; i < number_of_processes; i++)
    {
        printf("%c,%d,%d\n", processes[i]->name, processes[i]->arrive_time,
               processes[i]->service_time);
    }
    do_scheduling(policy, processes, last_instant);

    return 0;
}
