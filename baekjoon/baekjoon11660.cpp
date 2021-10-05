#include <iostream>

using namespace std;

int x1, x2, y1, y2;
int arr[1025][1025];
int dp[1025][1025];

int map_sum(int tx1, int ty1, int tx2, int ty2)
{
  return 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
    }
  }

  //    for(int i = 1; i <= n; i++)
  //    {
  //        for(int j = 1; j <= n; j++)
  //        {
  //            cout << dp[i][j] << " ";
  //        }
  //        cout << '\n';
  //    }

  for (int i = 0; i < m; i++)
  {
    int tx1, tx2, ty1, ty2;

    cin >> tx1 >> ty1 >> tx2 >> ty2;

    cout << dp[tx2][ty2] - dp[tx1 - 1][ty2] - dp[tx2][ty1 - 1] + dp[tx1 - 1][ty1 - 1] << '\n';
  }
}
