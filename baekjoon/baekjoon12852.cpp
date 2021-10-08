#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dp[1000001];

int make_one(int n)
{
  if (n == 1)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = 987654321;

  if (n % 3 == 0)
    dp[n] = min(dp[n], 1 + make_one(n / 3));
  if (n % 2 == 0)
    dp[n] = min(dp[n], 1 + make_one(n / 2));
  dp[n] = min(dp[n], 1 + make_one(n - 1));

  return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << make_one(n) << '\n';

  dp[1] = 0;
  //    for(int i = 2; i <= n; i ++)
  //        cout << dp[i] << " ";

  while (n != 0)
  {
    cout << n << " ";
    if (dp[n] == dp[n - 1] + 1)
      n = n - 1;
    else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
      n = n / 3;
    else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
      n = n / 2;
  }
}
