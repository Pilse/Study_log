#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int map[501][501];
int dp[501][501];

int path(int sy, int sx, int ey, int ex)
{
    cout << ey << " " << ex << "\n";

    if (sy == ey && sx == ex)
    {
        cout << "[case1] return 1 " << '\n';
        return 1;
    }
    if (dp[ey][ex])
    {
        cout << "[case2] return " << dp[ey][ex] << '\n';
        return dp[ey][ex];
    }

    int t1 = 0, t2 = 0, t3 = 0, t4 = 0;

    if (ex - 1 >= 0 && map[ey][ex - 1] > map[ey][ex])
    {
        cout << "[path1]";
        t1 += path(sy, sx, ey, ex - 1);
    }

    if (ey - 1 >= 0 && map[ey - 1][ex] > map[ey][ex])
    {
        cout << "[path3]";
        t3 += path(sy, sx, ey - 1, ex);
    }

    dp[ey][ex] = t1 + t2 + t3 + t4;

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

    int result = path(0, 0, n - 1, m - 1);
    cout << result << '\n';
}
