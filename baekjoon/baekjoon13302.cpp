#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, m;
int dp[1001][1001];
int arr[1001];

int price(int day, int coupon)
{
  if (day > n)
    return 0;
  if (dp[day][coupon] != INF)
    return dp[day][coupon];
  if (!arr[day])
    return dp[day][coupon] = price(day + 1, coupon);

  dp[day][coupon] = min({dp[day][coupon], price(day + 1, coupon) + 10000, price(day + 3, coupon + 1) + 25000, price(day + 5, coupon + 2) + 37000});
  if (coupon > 2)
    dp[day][coupon] = min(dp[day][coupon], price(day + 1, coupon - 3));

  return dp[day][coupon];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int temp;

  cin >> n >> m;

  fill(&dp[0][0], &dp[1000][1000], INF);
  fill(arr, &arr[1000], 1);

  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    arr[temp] = 0;
  }

  cout << price(1, 0) << '\n';
}
