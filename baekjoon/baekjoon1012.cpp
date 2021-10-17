#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[51][51];
int visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int X, Y;

void bfs(int x, int y)
{
    visited[x][y] = 1;

    queue<pair<int, int> > q;
    q.push({x, y});

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newx = curx + dx[i];
            int newy = cury + dy[i];

            if (newx < 0 || newy < 0 || newx > X || newy > Y)
                continue;
            if (arr[newx][newy] && !visited[newx][newy])
            {
                visited[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int k, cnt = 0;
        cin >> X >> Y >> k;

        for (int i = 0; i < k; i++)
        {
            int tx, ty;
            cin >> tx >> ty;

            arr[tx][ty] = 1;
        }

        for (int i = 0; i < X; i++)
        {
            for (int j = 0; j < Y; j++)
            {
                if (arr[i][j] && !visited[i][j])
                {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

        fill(&arr[0][0], &arr[50][50], 0);
        fill(&visited[0][0], &visited[50][50], 0);
    }
}
