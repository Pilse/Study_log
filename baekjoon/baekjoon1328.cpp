#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, left_cnt, right_cnt;
vector<int> vec;

long long dp[101][101][101];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> left_cnt >> right_cnt;

  dp[1][1][1] = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int l = 1; l <= left_cnt; l++)
    {
      for (int r = 1; r <= right_cnt; r++)
        dp[i][l][r] = (dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1] + dp[i - 1][l][r] * (i - 2)) % 1000000007;
    }
  }
  cout << dp[n][left_cnt][right_cnt] % 1000000007;
}
