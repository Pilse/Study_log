#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<long long>> g(n, vector<long long>(n));

  for (auto &r : g)
    for (auto &v : r)
      cin >> v;

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
  vector<int> visited(n, 0);
  long long cost = 0;

  pq.push({0, 0});

  while (!pq.empty())
  {
    long long cur_cost = pq.top().first;
    int cur_pos = pq.top().second;
    pq.pop();

    if (visited[cur_pos])
      continue;
    visited[cur_pos] = 1;
    cost += cur_cost;

    for (int i = 0; i < n; i++)
    {
      if (visited[i] || !g[cur_pos][i])
        continue;
      pq.push({g[cur_pos][i], i});
    }
  }
  cout << cost << '\n';
}
