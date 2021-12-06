#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> v;

void turn_right(int gear)
{
    string substr = "";
    substr += v[gear][v[gear].size() - 1];
    substr += v[gear].substr(0, v[gear].size() - 1);
    
    cout << v[gear] << " " << substr << '\n';
    
    v[gear] = substr;
}

void turn_left(int gear)
{
    string substr = "";
    substr += v[gear].substr(1, v[gear].size() - 1);
    substr += v[gear][0];
    
    cout << v[gear] << " " << substr << '\n';
    
    v[gear] = substr;
}

void turn_gear(int gear, int cmd)
{
    if(cmd == 1)
        turn_right(gear);
    else
        turn_left(gear);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, t, cmd, gear;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        string str;
        
        cin >> str;
        
        v.push_back(str);
    }
    
    cin >> t;
    
    while(t--)
    {
        cin >> gear >> cmd;
        
        int min = gear - 2;
        int max = gear;
        
        cout << gear << cmd << min << max << '\n';
        
        turn_gear(gear - 1, cmd);
        
        for(; max < N && (v[max][0] != v[max - 1][4]); max++)
        {
            cout << gear << " " << v[max][0] << " " << v[max - 1][4] << '\n';
            int dir = (max - gear + 1) % 2 ? -1 : 1;
            turn_gear(max, cmd * dir);
        }
        for(; min >= 0 && (v[min][4] != v[min + 1][0]); min--)
        {
            int dir = (gear - min) % 2 ? -1 : 1;
            turn_gear(min, cmd * dir);
        }
        
    }
    
    int cnt = 0;
    
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i][2] == '1')
            cnt++;
    }
    cout << cnt << '\n';
    
}
