#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<long long>> dp[2];

long long dfs(int cur, int left, int first);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  dp[0].resize(n, vector<long long>(n, 0));
  dp[1].resize(n, vector<long long>(n, 0));

  long long tot = 0;
  for (int i = 0; i < n - (k - 1) * 2; i++)
    tot = (tot + dfs(i, k - 1, i == 0 ? 0 : 1)) % 1000000003;
  cout << tot << '\n';
}

long long dfs(int cur, int left, int first)
{
  if (left == 0)
    return 1;
  if (dp[first][cur][left])
    return dp[first][cur][left];

  for (int i = cur + 2; i < n - (left - 1) * 2; i++)
  {
    if (i == n - 1 && first == 0)
      continue;
    dp[first][cur][left] = (dp[first][cur][left] + dfs(i, left - 1, first)) % 1000000003;
  }
  return dp[first][cur][left];
}
