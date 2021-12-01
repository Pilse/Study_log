#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, temp;
    vector<int> v;
    
    cin >> n;
    
    for(int i = 0; i < n * n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    
    while(n != 1)
    {
        int idx = 0;
        vector<int> _v;
        
        while(idx < v.size())
        {
            vector<int> _t;
            _t.push_back(v[idx]);
            _t.push_back(v[idx + 1]);
            _t.push_back(v[idx + n]);
            _t.push_back(v[idx + n + 1]);
            sort(_t.begin(), _t.end(), greater<int>());
            
            _v.push_back(_t[1]);
            
            idx += 2;
            if(idx % n == 0) idx += n;
        }
        
        vector<int>().swap(v);
        v.assign(_v.begin(), _v.end());
        
        n /= 2;
    }
    
    cout << v[0] << '\n';;
}
