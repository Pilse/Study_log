#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, w, l, t;
    int tot = 0;
    int idx = 0;
    int sum = 0;
    vector<int> vec;
    queue<int> q;
    
    cin >> n >> w >> l;
    
    tot += w;
    
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
    }
    
    while(idx < n)
    {
        if(q.size() == w)
        {
            sum -= q.front();
            q.pop();
        }
        
        if(sum + vec[idx] > l)
            q.push(0);
        else
        {
            q.push(vec[idx]);
            sum += vec[idx];
            idx++;
        }
        
        tot++;
    }
    
    cout << tot << '\n';
}
