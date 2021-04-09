#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int map[501][501];
int dp[501][501];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

//int path(int ey, int ex)
//{
//    if(ey == 0 && ex == 0)
//        return 1;
//
//    if(dp[ey][ex] != -1)
//        return dp[ey][ex];
//
//
//    dp[ey][ex] = 0;
//
//    if(ex - 1 >= 0 && map[ey][ex - 1] > map[ey][ex])
//        dp[ey][ex] += path(ey, ex - 1);
//    if(ey - 1 >= 0 && map[ey - 1][ex] > map[ey][ex])
//        dp[ey][ex] += path(ey - 1, ex);
//    if(ex + 1 <= m - 1 && map[ey][ex + 1] > map[ey][ex])
//        dp[ey][ex] += path(ey, ex + 1);
//    if(ey + 1 <= n - 1 && map[ey + 1][ex] > map[ey][ex])
//        dp[ey][ex] += path(ey + 1, ex);
//
//
//    return dp[ey][ex];
//}
int path(int ey, int ex)
{
    if (ey == n - 1 && ex == m - 1)
        return 1;

    if (dp[ey][ex] != -1)
        return dp[ey][ex];

    dp[ey][ex] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = ey + dy[i];
        int nx = ex + dx[i];
        if (ny >= 0 && nx >= 0 && ny < n && nx < m)
        {
            if (map[ey][ex] > map[ny][nx])
            {
                dp[ey][ex] += path(ny, nx);
            }
        }
    }
    return dp[ey][ex];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    //    int result = path(n - 1, m - 1);
    int result = path(0, 0);
    cout << result << '\n';
}
