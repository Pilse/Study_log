#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

void init();
void input();
int dijkstra();
void remove_shortest_path();

int N, M, S, D;
vector<pair<int, int> > Map[501];
vector<int> Parent[501];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (1)
  {
    init();

    input();

    if (N == 0 && M == 0)
      break;

    dijkstra();

    remove_shortest_path();

    int ans = dijkstra();

    if (ans == INF)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
}

void init()
{
  for (int i = 0; i < 501; i++)
  {
    vector<pair<int, int> >().swap(Map[i]);
    vector<int>().swap(Parent[i]);
  }
}

void input()
{
  cin >> N >> M;

  if (N == 0 && M == 0)
    return;

  cin >> S >> D;

  for (int i = 0; i < M; i++)
  {
    int s, d, c;

    cin >> s >> d >> c;

    Map[s].push_back({d, c});
  }
}

int dijkstra()
{
  int dist[N];
  priority_queue<pair<int, int> > pq;

  for (int i = 0; i < N; i++)
    dist[i] = INF;

  dist[S] = 0;

  pq.push({0, S});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int node = pq.top().second;

    pq.pop();

    if (dist[node] < cost)
      continue;

    for (int i = 0; i < Map[node].size(); i++)
    {
      int next_node = Map[node][i].first;
      int next_cost = Map[node][i].second;

      if (next_cost == -1)
        continue;

      if (dist[next_node] > cost + next_cost)
      {
        dist[next_node] = cost + next_cost;

        pq.push({-(cost + next_cost), next_node});

        Parent[next_node].clear();
        Parent[next_node].push_back(node);
      }

      else if (dist[next_node] == cost + next_cost)
        Parent[next_node].push_back(node);
    }
  }

  return dist[D];
}

void remove_shortest_path()
{
  int visited[501] = {
      0,
  };

  queue<int> q;

  visited[D] = 1;

  q.push(D);

  while (!q.empty())
  {
    int node = q.front();

    q.pop();

    for (int i = 0; i < Parent[node].size(); i++)
    {
      int parent = Parent[node][i];

      if (!visited[parent])
      {
        visited[parent] = 1;
        q.push(parent);
      }

      for (int j = 0; j < Map[parent].size(); j++)
      {
        if (Map[parent][j].first == node)
        {
          Map[parent][j].second = -1;

          break;
        }
      }
    }
  }
}
