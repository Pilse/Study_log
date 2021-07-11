#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t;
    int day = 0;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        pq.push(t);
    }
    
    for(int i = 1; i <= n; i++)
    {
        day = max(day, i + pq.top());
//        cout << day << " ";
        pq.pop();
    }
    
    cout << day + 1 << '\n';
}
