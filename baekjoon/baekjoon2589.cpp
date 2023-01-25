#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int sr, int sc, vector<vector<int>> &g);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c;

  vector<vector<int>> g(r + 1, vector<int>(c + 1, 0));

  for (int i = 0; i < r; i++)
  {
    string str;
    cin >> str;
    for (int j = 0; j < c; j++)
    {
      g[i][j] = str[j] == 'L' ? 1 : 0;
    }
  }

  int answer = 0;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      if (g[i][j])
      {
        answer = max(answer, bfs(i, j, g));
      }
    }
  }

  cout << answer << '\n';
}

int bfs(int sr, int sc, vector<vector<int>> &g)
{
  vector<vector<int>> visited(r + 1, vector<int>(c + 1, 0));
  visited[sr][sc] = 1;

  queue<pair<pair<int, int>, int>> q;
  q.push({{sr, sc}, 0});

  int dist = 0;
  while (!q.empty())
  {
    auto &[pos, cd] = q.front();
    q.pop();

    dist = max(dist, cd);

    for (int i = 0; i < 4; i++)
    {
      int nr = pos.first + dr[i];
      int nc = pos.second + dc[i];

      if (nr < 0 || nc < 0 || nr >= r || nc >= c || !g[nr][nc] || visited[nr][nc])
        continue;

      visited[nr][nc] = 1;
      q.push({{nr, nc}, cd + 1});
    }
  }
  return dist;
}
