#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> g(n + 1, vector<int>(n + 1, 1e5));

  while (k--)
  {
    int t1, t2;
    cin >> t1 >> t2;
    g[t1][t2] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (g[i][j] > g[i][k] + g[k][j])
          g[i][j] = g[i][k] + g[k][j];
      }
    }
  }

  int s;
  cin >> s;
  while (s--)
  {
    int t1, t2;
    cin >> t1 >> t2;

    if (g[t1][t2] == 1e5 && g[t2][t1] == 1e5)
    {
      cout << 0 << '\n';
      continue;
    }

    if (g[t1][t2] == g[t2][t1])
    {
      cout << 0 << '\n';
      continue;
    }

    if (g[t1][t2] < g[t2][t1])
    {
      cout << -1 << '\n';
      continue;
    }

    cout << 1 << '\n';
  }
}
