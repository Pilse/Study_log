#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int MIN_BASE = 1;
int MAX_BASE;
int CUR_BASE;
int map[102][102];
int visited[102][102];
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void bfs(int i, int j)
{
  visited[i][j] = 1;

  queue<pair<int, int> > q;

  q.push({i, j});

  while (!q.empty())
  {
    int curi = q.front().first;
    int curj = q.front().second;
    q.pop();

    for (int n = 0; n < 4; n++)
    {
      int newi = curi + di[n];
      int newj = curj + dj[n];

      if (newi < 1 || newj < 1 || newi > N || newj > N)
        continue;
      if ((map[newi][newj] > CUR_BASE) && !visited[newi][newj])
      {
        visited[newi][newj] = 1;
        q.push({newi, newj});
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int cnt = 0, res = 1;

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cin >> map[i][j];
      MIN_BASE = min(MIN_BASE, map[i][j]);
      MAX_BASE = max(MAX_BASE, map[i][j]);
    }
  }

  for (int base = MIN_BASE; base < MAX_BASE; base++)
  {
    CUR_BASE = base;
    cnt = 0;

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if ((map[i][j] > CUR_BASE) && !visited[i][j])
        {
          cnt++;
          bfs(i, j);
        }
      }
    }
    res = max(res, cnt);

    fill(&visited[0][0], &visited[101][101], 0);
  }

  cout << res << '\n';
}
