#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string str;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        
        vector<int> v;
        
        for(int j = 0; j < str.length(); j++)
            v.push_back(str[j] - '0');
        
        if(next_permutation(v.begin(), v.end()))
        {
            for(int j = 0; j < str.length(); j++)
                cout << char(v[j] + 48);
        }
        else
            cout << str;
        
        cout << '\n';
    }
}
