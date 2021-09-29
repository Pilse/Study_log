#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int maze[1001][1001];
int dp[1001][1001];
int n, m;

int candy_path(int y, int x)
{
    if(y > n || x > m)
        return 0;
    if(y == n && x == m)
        return maze[y][x];
    
    if(dp[y][x] != -1)
        return dp[y][x];
    
    return dp[y][x] = maze[y][x] + max({candy_path(y + 1, x), candy_path(y, x + 1), candy_path(y + 1, x + 1)});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> maze[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout << candy_path(0, 0) << '\n';;
}
