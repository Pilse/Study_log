#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, m, a, b, cnt = 0;
    cin >> n >> m;

    vector<pair<int, int>> vec;
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
      cin >> a >> b;
      vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
         {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second; });

    for (auto &[start, end] : vec)
    {
      int idx = start;

      while (visited[idx] == 1 && idx <= end)
        idx++;

      if (idx > end)
        continue;

      visited[idx] = 1;
      cnt++;
    }

    cout << cnt << '\n';
  }
}
