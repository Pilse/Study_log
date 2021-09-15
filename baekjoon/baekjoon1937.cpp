#include <iostream>
#include <cstring>

using namespace std;

int n;
int map[502][502];
int dp[502][502];

int bamboo(int y, int x)
{
  if (dp[y][x] != -1)
    return dp[y][x];

  dp[y][x] = 1;

  if (y - 1 > 0 && (map[y - 1][x] > map[y][x]))
    dp[y][x] = max(dp[y][x], 1 + bamboo(y - 1, x));
  if (y + 1 <= n && (map[y + 1][x] > map[y][x]))
    dp[y][x] = max(dp[y][x], 1 + bamboo(y + 1, x));
  if (x - 1 > 0 && (map[y][x - 1] > map[y][x]))
    dp[y][x] = max(dp[y][x], 1 + bamboo(y, x - 1));
  if (x + 1 <= n && (map[y][x + 1] > map[y][x]))
    dp[y][x] = max(dp[y][x], 1 + bamboo(y, x + 1));

  return dp[y][x];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> map[i][j];
    }
  }

  int largest = 0;
  memset(dp, -1, sizeof(dp));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      largest = max(largest, bamboo(i, j));
    }
  }
  cout << largest << '\n';
}
