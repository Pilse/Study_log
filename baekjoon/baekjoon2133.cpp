#include <iostream>

using namespace std;

int dp[31];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  dp[0] = 1;
  dp[1] = 0;
  dp[2] = 3;

  for (int i = 3; i <= 30; i++)
  {
    if (i % 2 != 0)
      dp[i] = 0;
    else
    {
      dp[i] = dp[i - 2] * dp[2];
      for (int j = i - 4; j >= 0; j = j - 2)
      {
        dp[i] += dp[j] * 2;
      }
    }
  }

  cout << dp[n] << '\n';
}
