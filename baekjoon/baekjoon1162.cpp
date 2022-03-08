#include <iostream>
#include <vector>
#include <queue>

#define INF 9223372036854775800

using namespace std;

struct node
{
  long long cost;
  int target;
  int step;
};

struct compare
{
  bool operator()(node &a, node &b)
  {
    return a.cost > b.cost;
  }
};

void input();
void bfs();

int N, M, K;
vector<pair<int, int> > Map[10001];
long long Costs[21][10001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  bfs();
}

void input()
{
  cin >> N >> M >> K;

  for (int i = 0; i < M; i++)
  {
    int s, t, c;

    cin >> s >> t >> c;

    Map[s].push_back({t, c});
    Map[t].push_back({s, c});
  }

  for (int i = 0; i < 21; i++)
    for (int j = 0; j < 10001; j++)
      Costs[i][j] = INF;
}

void bfs()
{
  priority_queue<node, vector<node>, compare> q;
  long long min_cost = INF;

  Costs[0][1] = 0;

  q.push({0, 1, 0});

  while (!q.empty())
  {
    long long cost = -q.top().cost;
    int node = q.top().target;
    int step = q.top().step;

    q.pop();

    if (cost >= min_cost)
      continue;

    if (node == N)
    {
      min_cost = cost;

      continue;
    }

    for (int i = 0; i < Map[node].size(); i++)
    {
      int next_node = Map[node][i].first;
      long long next_cost = Map[node][i].second;

      if (step < K && Costs[step + 1][next_node] > cost)
      {
        Costs[step + 1][next_node] = cost;
        q.push({-cost, next_node, step + 1});
      }

      if (Costs[step][next_node] <= next_cost + cost)
        continue;

      if (next_cost + cost >= min_cost)
        continue;

      Costs[step][next_node] = next_cost + cost;

      q.push({-(next_cost + cost), next_node, step});
    }
  }

  cout << min_cost << '\n';
}
