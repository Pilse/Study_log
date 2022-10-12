#include <iostream>
#include <vector>

using namespace std;

int dfs(int visited, int cur, int cost);

int n;
vector<int> dp;
vector<vector<int>> g;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  g.resize(n, vector<int>(n, 0));
  dp.resize(1 << (n + 0), 0);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> g[i][j];

  cout << dfs(0, 0, 0) << '\n';
}

int dfs(int visited, int cur, int cost)
{
  if (cur == n)
    return cost;

  if (dp[visited])
    return dp[visited];

  dp[visited] = 1e8;
  for (int i = 0; i < n; i++)
  {
    if (visited & (1 << i))
      continue;
    dp[visited] = min(dp[visited], dfs(visited | (1 << i), cur + 1, cost + g[cur][i]));
  }
  return dp[visited];
}
