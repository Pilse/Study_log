#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int ans = 0;

  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (arr[i] > arr[j])
        dp[i] = max(dp[j] + 1, dp[i]);
    }
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
}
