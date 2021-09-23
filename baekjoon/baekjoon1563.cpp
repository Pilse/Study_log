#include <iostream>
#include <cstring>

using namespace std;

int dp[1001][3][4];
int n;

int attend(int day, int late, int abs)
{
  if (late >= 2 || abs >= 3)
    return 0;
  if (day == n)
    return 1;
  if (dp[day][late][abs] != -1)
    return dp[day][late][abs];
  return dp[day][late][abs] = ((attend(day + 1, late, 0) % 1000000) + (attend(day + 1, late + 1, 0) % 1000000) + (attend(day + 1, late, abs + 1) % 1000000)) % 1000000;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;

  cout << attend(0, 0, 0);
}
