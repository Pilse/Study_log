#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[1010][1010];
int visited[1010][1010];
queue<pair<pair<int, int>, int> > q;
int n, m;
int h, w, sy, sx, ey, ex;

int test(int y, int x, int dir)
{
    if (dir == 0)
    {
        for (int i = 0; i < w; i++)
        {
            if (y + h - 1 > n)
                return 0;
            if (arr[y + h - 1][x + i] == 1)
                return 0;
        }
        return 1;
    }
    if (dir == 1)
    {
        for (int i = 0; i < w; i++)
        {
            if (arr[y][x + i] == 1)
                return 0;
        }
        return 1;
    }
    if (dir == 2)
    {
        for (int i = 0; i < h; i++)
        {
            if (x + w - 1 > m)
                return 0;
            if (arr[y + i][x + w - 1] == 1)
                return 0;
        }
        return 1;
    }
    if (dir == 3)
    {
        for (int i = 0; i < h; i++)
        {
            if (arr[y + i][x] == 1)
                return 0;
        }
        return 1;
    }
    return 0;
}

void bfs(int c, int r)
{
    q.push({{sy, sx}, 0});
    visited[sy][sx] = 1;

    while (!q.empty())
    {
        int cury = q.front().first.first;
        int curx = q.front().first.second;
        int acc = q.front().second;
        q.pop();

        if (cury == ey && curx == ex)
        {
            cout << acc << '\n';
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];
            if (!visited[ny][nx] && ny > 0 && nx > 0 && ny <= r && nx <= c && arr[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                if (test(ny, nx, i))
                {
                    q.push({{ny, nx}, acc + 1});
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> h >> w >> sy >> sx >> ey >> ex;

    bfs(n, m);
}
