#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<>> pq;
  vector<pair<int, int>> vec;
  int n, cnt = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int st, en;
    cin >> st >> en;
    vec.push_back({st, en});
  }

  sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b)
       { return a.first < b.first; });

  for (auto &[st, en] : vec)
  {
    if (pq.empty())
    {
      pq.push(en);
      cnt++;
      continue;
    }

    int top = pq.top();
    if (top <= st)
    {
      pq.pop();
      pq.push(en);
      continue;
    }

    pq.push(en);
    cnt++;
  }

  cout << cnt << '\n';
}
