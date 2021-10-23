#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int w, h;
int map[52][52];
int visited[52][52];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void bfs(int y, int x)
{
  visited[y][x] = 1;

  queue<pair<int, int> > q;

  q.push({y, x});

  while (!q.empty())
  {
    int cury = q.front().first;
    int curx = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++)
    {
      int newy = cury + dy[i];
      int newx = curx + dx[i];

      if (newy < 1 || newx < 1 || newy > h || newx > w)
        continue;
      if (map[newy][newx] && !visited[newy][newx])
      {
        visited[newy][newx] = 1;
        q.push({newy, newx});
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> w >> h;

  while (w != 0 && h != 0)
  {
    int cnt = 0;

    for (int y = 1; y <= h; y++)
    {
      for (int x = 1; x <= w; x++)
      {
        cin >> map[y][x];
      }
    }

    for (int y = 1; y <= h; y++)
    {
      for (int x = 1; x <= w; x++)
      {
        if (map[y][x] && !visited[y][x])
        {
          //                    cout << y << " " << x << '\n';
          cnt++;
          bfs(y, x);
        }
      }
    }

    cout << cnt << '\n';

    cin >> w >> h;

    fill(&map[0][0], &map[51][51], 0);
    fill(&visited[0][0], &visited[51][51], 0);
  }
}
