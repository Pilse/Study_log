#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool bfs(vector<vector<char>> g, vector<pair<int, int>> &t, int i, int j, int k);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<char>> g(n, vector<char>(n));
  vector<pair<int, int>> t;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> g[i][j];
      if (g[i][j] == 'T')
        t.push_back({i, j});
    }
  }

  int size = n * n;
  for (int i = 0; i < size - 2; i++)
  {
    if (g[i / n][i % n] != 'X')
      continue;

    for (int j = i + 1; j < size - 1; j++)
    {
      if (g[j / n][j % n] != 'X')
        continue;

      for (int k = j + 1; k < size; k++)
      {
        if (g[k / n][k % n] != 'X')
          continue;

        if (bfs(g, t, i, j, k))
        {
          cout << "YES" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "NO" << '\n';
}

bool bfs(vector<vector<char>> g, vector<pair<int, int>> &t, int i, int j, int k)
{
  g[i / g.size()][i % g.size()] = 'O';
  g[j / g.size()][j % g.size()] = 'O';
  g[k / g.size()][k % g.size()] = 'O';

  int visited[g.size()][g.size()][4];
  fill(&visited[0][0][0], &visited[g.size() - 1][g.size() - 1][3], 0);

  queue<pair<pair<int, int>, int>> q;

  for (auto &pos : t)
  {
    for (int i = 0; i < 4; i++)
    {
      q.push({pos, i});
      visited[pos.first][pos.second][i] = 1;
    }
  }

  while (!q.empty())
  {
    pair<pair<int, int>, int> cur = q.front();
    pair<int, int> pos = cur.first;
    int dir = cur.second;
    q.pop();

    int nr = pos.first + dr[dir];
    int nc = pos.second + dc[dir];

    if (nr < 0 || nc < 0 || nc >= g.size() || nr >= g.size() || visited[nr][nc][dir])
      continue;

    if (g[nr][nc] == 'S')
      return false;
    if (g[nr][nc] == 'X')
    {
      visited[nr][nc][dir] = 1;
      q.push({{nr, nc}, dir});
    }
  }
  return true;
}
