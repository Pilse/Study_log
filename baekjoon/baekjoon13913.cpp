#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int MAX = 100001;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> prev(100001, -1);
  vector<int> visited(100001, 0);

  queue<pair<int, int>> q;
  visited[n] = 1;
  q.push({n, 0});

  while (!q.empty())
  {
    int cur = q.front().first;
    int cost = q.front().second;
    q.pop();

    if (cur == k)
    {
      cout << cost << '\n';
      break;
    }

    vector<int> nq;

    if (cur - 1 >= 0)
      nq.push_back(cur - 1);
    if (cur + 1 < 100001)
      nq.push_back(cur + 1);
    if (cur * 2 < 100001)
      nq.push_back(cur * 2);

    for (auto &next : nq)
    {
      if (!visited[next])
      {
        visited[next] = 1;
        prev[next] = cur;
        q.push({next, cost + 1});
      }
    }
  }

  vector<int> route;
  int cur = k;
  while (cur != n)
  {
    route.push_back(cur);
    cur = prev[cur];
  }
  route.push_back(n);
  reverse(route.begin(), route.end());
  for (auto r : route)
    cout << r << " ";
}
