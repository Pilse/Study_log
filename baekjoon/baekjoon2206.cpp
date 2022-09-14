#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct status
{
    int y;
    int x;
    int step;
    int passed;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n);

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        transform(str.begin(), str.end(), back_inserter(map[i]), [](char c)
                  { return c - '0'; });
    }

    queue<status> q;
    vector<vector<vector<int>>> visited(2, vector<vector<int>>(n, vector<int>(m, 1e8)));

    q.push({0, 0, 1, 0});
    visited[0][0][0] = 1;
    visited[1][0][0] = 1;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int step = q.front().step;
        int passed = q.front().passed;
        q.pop();

        if (y == n - 1 && x == m - 1)
        {
            cout << step << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nexty = y + dy[i];
            int nextx = x + dx[i];

            if (nexty < 0 || nextx < 0 || nexty >= n || nextx >= m)
                continue;
            if (visited[passed][nexty][nextx] <= step + 1)
                continue;

            if (!map[nexty][nextx])
            {
                visited[passed][nexty][nextx] = step + 1;
                q.push({nexty, nextx, step + 1, passed});
                continue;
            }

            if (passed)
                continue;
            if (visited[1][nexty][nextx] <= step + 1)
                continue;

            visited[1][nexty][nextx] = step + 1;
            q.push({nexty, nextx, step + 1, 1});
        }
    }

    cout << -1 << '\n';
}
