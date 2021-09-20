#include <iostream>

using namespace std;

pair<int, int> dp[31];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int d, k;

  cin >> d >> k;

  dp[1] = {1, 0};
  dp[2] = {0, 1};
  dp[3] = {1, 1};
  for (int i = 4; i <= d; i++)
  {
    dp[i] = {dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second};
  }
  int cx = dp[d].first;
  int cy = dp[d].second;

  for (int i = 1; i <= (k / cx); i++)
  {
    for (int j = 1; j <= (k / cy); j++)
    {
      if (cx * i + cy * j == k)
      {
        cout << i << '\n'
             << j << '\n';
        return 0;
      }
    }
  }
}
