#include <iostream>
#include <string>
#include <map>

using namespace std;

string START, END, QUIT;
int S_H, S_M, E_H, E_M, Q_H, Q_M;

pair<int, int> time_to_int(string time)
{
    int hour = time.substr(0, 1) == "0"
        ? stoi(time.substr(1, 1))
        : stoi(time.substr(0, 2));
    
    int minute = time.substr(3, 1) == "0"
        ? stoi(time.substr(4, 1))
        : stoi(time.substr(3, 2));
    
    return {hour, minute};
}

int is_before_start(int hour, int minute)
{
    if(hour < S_H)
        return 1;
    
    if(hour == S_H && minute <= S_M)
        return 1;
    
    return 0;
}

int is_after_end(int hour, int minute)
{
    if(hour > E_H)
        return 1;
    
    if(hour == E_H && minute >= E_M)
        return 1;
    
    return 0;
}

int is_before_quit(int hour, int minute)
{
    if(hour < Q_H)
        return 1;
    
    if(hour == Q_H && minute <= Q_M)
        return 1;
    
    return 0;
}

int calc_time(string t)
{
    pair<int, int> time = time_to_int(t);
    int hour = time.first;
    int minute = time.second;
    
    
    if(is_before_start(hour, minute)) return 1;
    if(is_after_end(hour, minute) && is_before_quit(hour, minute)) return 2;
    return 0;
}

void init()
{
    pair<int, int> start = time_to_int(START);
    S_H = start.first;
    S_M = start.second;
    
    pair<int, int> end = time_to_int(END);
    E_H = end.first;
    E_M = end.second;
    
    pair<int, int> quit = time_to_int(QUIT);
    Q_H = quit.first;
    Q_M = quit.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> START >> END >> QUIT;
    init();
    
    string time, name;
    int cnt = 0;
    map<string, int> m;
    
    while(cin >> time >> name)
    {
        if(calc_time(time) == 1)
        {
            if(m.find(name) == m.end())
                m[name] = 1;
            
        }
        else if(calc_time(time) == 2)
        {
            if(m.find(name) != m.end())
            {
                if(m[name] == 1)
                {
                    cnt ++;
                    m[name] = 2;
                }
            }
        }
    }
    
    cout << cnt << '\n';
    
}

