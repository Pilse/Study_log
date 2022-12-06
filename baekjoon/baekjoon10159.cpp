#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;

    g[t1][t2] = 1;
    g[t2][t1] = -1;
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (g[i][k] && g[i][k] == g[k][j])
          g[i][j] = g[i][k];

  for (int i = 1; i <= n; i++)
  {
    int cnt = 0;

    for (int j = 1; j <= n; j++)
      if (!g[i][j])
        cnt++;

    cout << cnt - 1 << '\n';
  }
}
