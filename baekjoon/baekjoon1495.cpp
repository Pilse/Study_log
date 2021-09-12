#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[110][1010];
vector<int> vec;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, s, m;
  int t;

  cin >> n >> s >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> t;
    vec.push_back(t);
  }

  if (s + vec[0] <= m)
    dp[0][s + vec[0]] = 1;
  if (s - vec[0] >= 0)
    dp[0][s - vec[0]] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (dp[i - 1][j])
      {
        if (j + vec[i] <= m)
          dp[i][j + vec[i]] = 1;
        if (j - vec[i] >= 0)
          dp[i][j - vec[i]] = 1;
      }
    }
  }
  for (int i = m; i >= 0; i--)
  {
    if (dp[n - 1][i])
    {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
