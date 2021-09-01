#include <iostream>

using namespace std;

long long dp[101][101];
int map[101][101];
int n;

long long route(int x, int y)
{
  //    cout << x << " " << y << '\n';
  if (dp[x][y] != -1)
    return dp[x][y];
  if (x == n && y == n)
    return 1;
  if (map[x][y] == 0)
    return 0;
  if (x > n || y > n)
    return 0;
  return dp[x][y] = route(x + map[x][y], y) + route(x, y + map[x][y]);
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
      dp[i][j] = -1;
    }
  }

  cout << route(1, 1);
}
