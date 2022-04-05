#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 987654321

using namespace std;

struct point
{
  int pos;
  int cost;
  int state;
  friend bool operator<(const point &a, const point &b)
  {
    return a.cost > b.cost;
  }
};

int Can_Visit[1001][1001];
vector<pair<int, int> > Edge[1001];
vector<int> Trap[1001];
vector<int> Trap_Index(1001, 0);

void handle_trap(int t)
{
  int visited[1001]{0};
  for (int i = 0; i < Trap[t].size(); i++)
  {
    int node = Trap[t][i];

    if (!visited[node])
    {
      visited[node] = 1;

      if (Can_Visit[t][node])
      {
        Can_Visit[t][node] = 0;
        Can_Visit[node][t] = 1;
      }
      else
      {
        Can_Visit[t][node] = 1;
        Can_Visit[node][t] = 0;
      }
    }
  }
}

int dijkstra(int n, int trap_size, int start, int end)
{
  vector<vector<int> > dist(1 << trap_size, vector<int>(n + 1, INF));
  dist[0][start] = 0;

  priority_queue<point> pq;

  pq.push({start, 0, 0});

  while (!pq.empty())
  {
    int cur_pos = pq.top().pos;
    int cur_cost = pq.top().cost;
    int cur_state = pq.top().state;

    pq.pop();

    if (Trap[cur_pos].size() > 0)
    {
      handle_trap(cur_pos);
      cur_state ^= (1 << Trap_Index[cur_pos]);
    }

    if (dist[cur_state][cur_pos] < cur_cost)
      continue;

    for (int i = 0; i < Edge[cur_pos].size(); i++)
    {
      int next_pos = Edge[cur_pos][i].first;
      int next_cost = Edge[cur_pos][i].second;

      if (!Can_Visit[cur_pos][next_pos])
        continue;

      if (dist[cur_state][next_pos] > cur_cost + next_cost)
      {
        dist[cur_state][next_pos] = cur_cost + next_cost;

        pq.push({next_pos, dist[cur_state][next_pos], cur_state});
      }
    }
  }

  int res = INF;
  for (int i = 0; i < dist.size(); i++)
    res = min(res, dist[i][end]);
  return res;
}

int solution(int n, int start, int end, vector<vector<int> > roads, vector<int> traps)
{
  for (int i = 0; i < roads.size(); i++)
  {
    int n1 = roads[i][0];
    int n2 = roads[i][1];
    int cost = roads[i][2];
    bool trap = false;

    for (int j = 0; j < traps.size(); j++)
    {
      if (n1 == traps[j])
      {
        trap = true;
        Trap[n1].push_back(n2);
      }
      if (n2 == traps[j])
      {
        trap = true;
        Trap[n2].push_back(n1);
      }
    }

    Edge[n1].push_back({n2, cost});
    Can_Visit[n1][n2] = 1;

    if (trap)
      Edge[n2].push_back({n1, cost});
  }

  for (int i = 0; i < traps.size(); i++)
  {
    Trap_Index[traps[i]] = i;
  }

  int answer = dijkstra(n, traps.size(), start, end);

  return answer;
}