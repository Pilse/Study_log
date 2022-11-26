#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

void dijkstra(vector<pair<int, int>> *g, int size, int start);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, d, c;
    cin >> n >> d >> c;
    vector<pair<int, int>> g[n + 1];

    for (int i = 0; i < d; i++)
    {
      int a, b, s;
      cin >> a >> b >> s;
      g[b].push_back({a, s});
    }

    dijkstra(g, n, c);
  }
}

void dijkstra(vector<pair<int, int>> *g, int size, int start)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  vector<int> visited(size + 1, 0);
  vector<int> dist(size + 1, 1e8);

  dist[start] = 0;

  int cnt = 0, max_time = 0;

  pq.push({0, start});
  while (!pq.empty())
  {
    auto [cur_cost, cur_pos] = pq.top();
    pq.pop();

    if (cur_cost > dist[cur_pos])
      continue;
    if (!visited[cur_pos])
    {
      visited[cur_pos] = 1;
      cnt++;
    }
    max_time = cur_cost;

    for (auto v : g[cur_pos])
    {
      auto [next_pos, next_cost] = v;
      int cost = cur_cost + next_cost;
      if (dist[next_pos] > cost)
      {
        dist[next_pos] = cost;
        pq.push({cost, next_pos});
      }
    }
  }

  cout << cnt << " " << max_time << '\n';
}
