#include <iostream>
#include <cstring>

using namespace std;

int dp[17][65537];
int map[17][17];
int n;

int dfs(int cur, int visited)
{
  if (visited == (1 << n) - 1)
  {
    if (map[cur][0] == 0)
      return 987654321;
    return map[cur][0];
  }

  if (dp[cur][visited] != -1)
    return dp[cur][visited];
  dp[cur][visited] = 987654321;

  for (int i = 0; i < n; i++)
  {
    if (!map[cur][i])
      continue;
    if (visited & (1 << i))
      continue;

    int updated_visited = visited | (1 << i);
    dp[cur][visited] = min(dp[cur][visited], map[cur][i] + dfs(i, updated_visited));
  }

  return dp[cur][visited];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }

  cout << dfs(0, 1) << '\n';
  ;
}
