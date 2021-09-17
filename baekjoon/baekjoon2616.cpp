#include <iostream>

using namespace std;

int dp[4][50002];
int sum[50002];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tot, each;

  cin >> tot;

  for (int i = 1; i <= tot; i++)
  {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }

  cin >> each;

  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= tot; j++)
    {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][max(0, j - each)] + sum[j] - sum[max(0, j - each)]);
      //            cout << dp[i][j] << " ";
    }
    //        cout << '\n';
  }

  cout << dp[3][tot] << '\n';
}
