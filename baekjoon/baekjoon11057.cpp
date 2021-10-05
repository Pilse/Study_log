#include <iostream>

using namespace std;

int dp[10][1001];

int asce(int a, int b)
{
  //    cout << a << " " << b << " " << dp[a][b] << '\n';
  if (dp[a][b])
    return dp[a][b];

  for (int i = a; i < 10; i++)
    dp[a][b] += asce(i, b - 1) % 10007;
  return dp[a][b] % 10007;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  dp[0][2] = 55;
  dp[0][1] = 10;

  for (int i = 1; i < 10; i++)
  {
    dp[i][2] = dp[i - 1][2] - (10 - i + 1);
    dp[i][1] = 10 - i;
  }

  cout << asce(0, n) << '\n';
}
