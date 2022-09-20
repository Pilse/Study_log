#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
  vector<vector<pair<int, int>>> edges(n + 1);
  vector<pair<int, int>> cases;
  vector<int> answer(2, 1e8);

  sort(summits.begin(), summits.end());
  sort(paths.begin(), paths.end());

  for (auto &path : paths)
  {
    edges[path[0]].push_back({path[1], path[2]});
    edges[path[1]].push_back({path[0], path[2]});
  }

  for (auto &edge : edges)
    sort(edge.begin(), edge.end(), [](pair<int, int> &v1, pair<int, int> &v2)
         { return v1.second > v2.second; });

  for (auto &gate : gates)
  {
    vector<int> costs(n + 1, 1e8);
    for (auto &g : gates)
      costs[g] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, gate});

    costs[gate] = 0;

    while (!pq.empty())
    {
      int cur_cost = pq.top().first;
      int cur_pos = pq.top().second;
      pq.pop();

      if (cur_cost > min(costs[cur_pos], answer[1]))
        continue;

      if (binary_search(summits.begin(), summits.end(), cur_pos))
      {
        if (answer[1] < cur_cost)
          continue;
        if (answer[1] > cur_cost || answer[0] > cur_pos)
        {
          answer[0] = cur_pos;
          answer[1] = cur_cost;
        }
        continue;
      }

      for (auto &edge : edges[cur_pos])
      {
        int next_pos = edge.first;
        int next_cost = max(cur_cost, edge.second);

        if (costs[next_pos] > next_cost)
        {
          costs[next_pos] = next_cost;
          pq.push({next_cost, next_pos});
        }
      }
    }
  }

  return answer;
}