#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, s, e;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n + 1);
  vector<int> dist(n + 1, 1e8);
  vector<int> prev(n + 1, -1);

  for (int i = 0; i < m; i++)
  {
    int t1, t2, c;
    cin >> t1 >> t2 >> c;
    g[t1].push_back({t2, c});
  }

  cin >> s >> e;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty())
  {
    int cur_cost = pq.top().first;
    int cur_pos = pq.top().second;
    pq.pop();

    if (dist[cur_pos] < cur_cost)
      continue;

    for (auto n : g[cur_pos])
    {
      int next_pos = n.first;
      int next_cost = n.second + cur_cost;
      if (dist[next_pos] > next_cost)
      {
        dist[next_pos] = next_cost;
        pq.push({next_cost, next_pos});
        prev[next_pos] = cur_pos;
      }
    }
  }

  cout << dist[e] << '\n';

  vector<int> path;
  int cur = e;
  while (cur != s)
  {
    path.push_back(cur);
    cur = prev[cur];
  }
  path.push_back(s);

  reverse(path.begin(), path.end());

  cout << path.size() << '\n';
  for (auto p : path)
    cout << p << " ";
}
