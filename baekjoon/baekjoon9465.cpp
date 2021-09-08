#include <iostream>
#include <string.h>

using namespace std;

int map[2][100001];
int dp[2][100001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--)
    {
        int n;
        cin >> n;
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = dp[1][0] + map[0][1];
        dp[1][1] = dp[0][0] + map[1][1];
        
        for(int i = 2; i < n; i++)
        {
            dp[0][i] = max(dp[1][i - 1] + map[0][i], dp[1][i - 2] + map[0][i]);
            dp[1][i] = max(dp[0][i - 1] + map[1][i], dp[0][i - 2] + map[1][i]);
//            cout << dp[0][i] << " " << dp[1][i] << '\n';
        }
        
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }

}
