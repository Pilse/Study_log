#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &g, vector<pair<int, int>> &viruses, int i, int j, int k)
{
  vector<vector<int>> visited(n, vector<int>(m, 0));
  visited[i / m][i % m] = 1;
  visited[j / m][j % m] = 1;
  visited[k / m][k % m] = 1;

  queue<pair<int, int>> q;
  for (auto &virus : viruses)
  {
    q.push(virus);
    visited[virus.first][virus.second] = 1;
  }

  int cnt = 0;
  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = cur.first + dr[i];
      int nc = cur.second + dc[i];

      if (nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] || g[nr][nc])
        continue;

      visited[nr][nc] = 1;
      q.push({nr, nc});
      cnt++;
    }
  }

  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int area = 0, virus = INT_MAX;
  cin >> n >> m;

  vector<vector<int>> g(n, vector<int>(m, 0));
  vector<pair<int, int>> viruses;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> g[i][j];

      if (!g[i][j])
        area++;

      if (g[i][j] == 2)
        viruses.push_back({i, j});
    }
  }

  for (int i = 0; i < n * m; i++)
  {
    if (g[i / m][i % m] != 0)
      continue;
    for (int j = i + 1; j < n * m; j++)
    {
      if (g[j / m][j % m] != 0)
        continue;
      for (int k = j + 1; k < n * m; k++)
      {
        if (g[k / m][k % m] != 0)
          continue;

        virus = min(virus, bfs(g, viruses, i, j, k));
      }
    }
  }

  cout << area - virus - 3 << '\n';
}
