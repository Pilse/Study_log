#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(4);
    
    int tot = 0;
    string str;
    priority_queue<string, vector<string>, greater<>> pq;
    map<string, int> m;
    
    while(getline(cin, str))
    {
        if(m.find(str) == m.end())
        {
            m[str] = 1;
            pq.push(str);
        }
        else
            m[str] += 1;
        
        tot++;
    }
    
    while(!pq.empty())
    {
        str = pq.top();
        pq.pop();
        
        cout << str << " " << (double)m[str] * 100 / (double)tot << '\n';
    }
}
