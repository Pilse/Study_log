#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, temp;
    vector<string> v;
    int n;
    
    cin >> s;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        
        v.push_back(temp);
    }
    
    int s_length = (int)s.length();
    dp[0] = 1;
    
    for(int idx = 0; idx < s_length; idx++)
    {
        for(int i = 0; i < n; i++)
        {
            temp = s.substr(idx, (int)v[i].length());
        
            if(temp == v[i] && dp[idx])
                dp[idx + (int)temp.length()] = 1;
        }
        
    }
    
    cout << dp[s_length] << '\n';
}
