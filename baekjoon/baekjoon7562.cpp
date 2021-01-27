#include <iostream>
#include <queue>

using namespace std;

int map_size;
queue<pair<pair<int, int>, int>> q;
int visited[310][310];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int cnt;
pair<int, int> dest;

void bfs()
{
    while (!q.empty())
    {
        pair<int, int> p = q.front().first;
        cnt = q.front().second;
        if (p.first == dest.first && p.second == dest.second)
            break;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int x = p.second + dx[i];
            int y = p.first + dy[i];
            if (x < 0 || x >= map_size || y < 0 || y >= map_size)
                continue;
            if (!visited[y][x])
            {
                q.push({{y, x}, cnt + 1});
                visited[y][x] = 1;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> map_size;
        int x, y;
        cin >> y >> x;
        cin >> dest.first >> dest.second;

        q.push({{y, x}, 0});
        visited[y][x] = 1;

        bfs();
        cout << cnt << endl;

        cnt = 0;
        for (int q = 0; q < map_size; q++)
        {
            for (int w = 0; w < map_size; w++)
            {
                visited[q][w] = 0;
            }
        }
        queue<pair<pair<int, int>, int>>().swap(q);
    }
}