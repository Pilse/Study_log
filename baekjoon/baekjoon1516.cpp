#include <iostream>
#include <vector>

using namespace std;

int build_time[501];
int refe[501];
int result[501];
vector<int> vec[501];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int continue_f = 1;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    int t;

    cin >> t;
    build_time[i] = t;

    cin >> t;
    while (t != -1)
    {
      vec[t].push_back(i);
      refe[i]++;
      cin >> t;
    }
  }

  while (continue_f)
  {
    continue_f = 0;
    for (int i = 1; i <= n; i++)
    {
      if (refe[i] == 0)
      {
        refe[i]--;
        result[i] += build_time[i];
        for (int j = 0; j < vec[i].size(); j++)
        {
          refe[vec[i][j]]--;
          result[vec[i][j]] = max(result[vec[i][j]], result[i]);
        }
      }
      else if (refe[i] > 0)
        continue_f = 1;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << result[i] << '\n';
}
