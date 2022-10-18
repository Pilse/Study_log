#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct node
{
  int score;
  int r;
  int c;
};

bool compare(node a, node b)
{
  if (a.score == b.score)
  {
    if (a.r == b.r)
      return a.c > b.c;
    return a.r > b.r;
  }
  return a.score > b.score;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};

  int n;
  cin >> n;

  vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
  int squre_n = n * n;
  vector<int> info[squre_n + 1];

  while (squre_n--)
  {
    int t;
    vector<int> v(4);
    vector<node> scores;
    cin >> t >> v[0] >> v[1] >> v[2] >> v[3];
    info[t] = v;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (m[i][j])
          continue;

        int score = 0;
        for (int k = 0; k < 4; k++)
        {
          int ni = i + dr[k];
          int nj = j + dc[k];
          if (ni < 1 || nj < 1 || ni > n || nj > n)
            continue;

          if (!m[ni][nj])
          {
            score += 100;
            continue;
          }

          for (auto l : v)
          {
            if (l == m[ni][nj])
            {
              score += 1000;
              break;
            }
          }
        }
        scores.push_back({score, i, j});
      }
    }

    sort(scores.begin(), scores.end(), compare);
    m[scores[0].r][scores[0].c] = t;
  }

  int tot = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int cnt = 0;
      int t = m[i][j];
      for (int k = 0; k < 4; k++)
      {
        int ni = i + dr[k];
        int nj = j + dc[k];
        if (ni < 1 || nj < 1 || ni > n || nj > n)
          continue;

        for (auto l : info[t])
        {
          if (l == m[ni][nj])
          {
            cnt++;
            break;
          }
        }
      }
      if (cnt == 0)
        continue;
      tot += pow(10, cnt - 1);
    }
  }
  cout << tot << '\n';
}
