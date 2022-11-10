#include <bits/stdc++.h>
using namespace std;
struct process
{
    char name;
    int arrive;
    int service_time;
};

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
    vector<process> processes(number_of_processes);
    for (int i = 0; i < number_of_processes; i++)
    {
        string str;
        cin >> str;
        std::replace(str.begin(), str.end(), ',', ' '); // replace ':' by ' '
        vector<string> array;
        stringstream ss(str);
        string temp;
        while (ss >> temp)
            array.push_back(temp);
        processes[i].name = array[0][0];
        processes[i].arrive = stoi(array[1]);
        processes[i].service_time = stoi(array[2]);
    }
    cout << "mode: " << mode << endl;
    cout << "policy: " << policy << endl;
    printf("last_instant: %d\nnumber_of_processes:%d\n", last_instant, number_of_processes);
    for (int i = 0; i < number_of_processes; i++)
    {
        printf("%c,%d,%d\n", processes[i].name, processes[i].arrive, processes[i].service_time);
    }
    return 0;
}