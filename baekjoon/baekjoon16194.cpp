#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    dp[i] = arr[i];
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      dp[i] = min(dp[i], dp[i - j] + arr[j]);
    }
  }

  cout << dp[n] << '\n';
}
