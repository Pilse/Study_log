#include <iostream>
#include <string.h>

using namespace std;

int coins[21];
int dp[21][10001];
int target;
int n;

int cases(int idx, int tgt)
{
//    cout << idx << " " << tgt << '\n';
    
    if(dp[idx][tgt] != -1)
        return dp[idx][tgt];
    
    if(idx == 1 && tgt % coins[idx] == 0)
        return 1;
    
    if(idx == 1 && tgt % coins[idx] != 0)
        return 0;
    
    dp[idx][tgt] = 0;
    
    for(int i = 0; i <= tgt / coins[idx]; i++)
    {
        dp[idx][tgt] += cases(idx - 1, tgt - coins[idx] * i);
    }
    return dp[idx][tgt];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        
        cin >> n;
        
        for(int i = 1; i <= n; i++)
            cin >> coins[i];
        
        cin >> target;
        
        cout << cases(n, target) << '\n';
    }
}
