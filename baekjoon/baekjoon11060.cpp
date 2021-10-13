#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int n;
int arr[1001];
int dp[1001];

int jump(int num)
{

  if (num == n)
    return 0;

  if (dp[num] != INF)
    return dp[num];

  for (int i = 1; i <= arr[num]; i++)
  {
    if (num + i <= n)
      dp[num] = min(dp[num], 1 + jump(num + i));
  }

  return dp[num];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  fill(dp, dp + 1000, INF);

  dp[n] = 0;

  if (jump(1) == INF)
    cout << -1 << '\n';
  else
    cout << dp[1] << '\n';
}
