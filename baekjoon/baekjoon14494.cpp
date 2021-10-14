#include <iostream>

#define MOD 1000000007

using namespace std;

long long dp[1001][1001];

int n, m;

long long path(int y, int x)
{
  if (y <= 0 || x <= 0)
    return 0;

  if (dp[y][x])
    return dp[y][x];

  return dp[y][x] = (path(y - 1, x) % MOD + path(y, x - 1) % MOD + path(y - 1, x - 1) % MOD) % MOD;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    dp[1][i] = 1;
  for (int i = 1; i <= m; i++)
    dp[i][1] = 1;

  cout << path(n, m);
}
