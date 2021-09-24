#include <iostream>
#define INF -987654321

using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001][3];
int visited[1001][1001];

int dy[] = {0, 0, 1};
int dx[] = {1, -1, 0};

int dfs(int y, int x, int dir)
{
  if (y == n && x == m)
    return map[y][x];
  if (dp[y][x][dir] != INF)
    return dp[y][x][dir];

  visited[y][x] = 1;
  int biggest = INF;
  for (int i = 0; i < 3; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny > 0 && nx > 0 && ny <= n && nx <= m && !visited[ny][nx])
    {
      biggest = max(biggest, dfs(ny, nx, i));
    }
  }

  dp[y][x][dir] = biggest + map[y][x];
  visited[y][x] = 0;
  return dp[y][x][dir];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      cin >> map[i][j];
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
      dp[i][j][2] = INF;
      visited[i][j] = 0;
    }
  }

  cout << dfs(1, 1, 0) << '\n';
}
