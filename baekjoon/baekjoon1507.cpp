#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int roads[n][n];
  int visited[n][n];
  int tot = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> roads[i][j];

      visited[i][j] = 0;

      if (i < j)
        tot += roads[i][j];
    }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (j == k || i == k)
          continue;

        if (roads[i][j] > roads[i][k] + roads[k][j])
        {
          cout << -1 << '\n';
          exit(0);
        }

        if (roads[i][j] == roads[i][k] + roads[k][j] && !visited[i][j])
        {
          tot -= roads[i][j];
          visited[i][j] = 1;
        }
      }
    }
  }
  cout << tot << '\n';
}
