#include <iostream>

using namespace std;

int dp[201][201];

int summation(int n, int k)
{
  if (k == 2)
    return n + 1;

  if (k == 1)
    return 1;

  if (dp[n][k])
    return dp[n][k];

  for (int i = 0; i <= n; i++)
    dp[n][k] = (dp[n][k] + summation(n - i, k - 1) % 1000000000) % 1000000000;

  return dp[n][k] % 1000000000;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;

  cin >> n >> k;

  cout << summation(n, k) << '\n';
}
