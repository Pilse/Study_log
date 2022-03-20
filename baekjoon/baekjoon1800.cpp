#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct network
{
  int node;
  int cost;
  int use_free;
};

void input();
void bfs();

int N, P, K, Cost = INF;
vector<pair<int, int> > Edge[1001];
int Visited[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  bfs();
}

void input()
{
  cin >> N >> P >> K;

  for (int i = 0; i < P; i++)
  {
    int n1, n2, cost;

    cin >> n1 >> n2 >> cost;

    Edge[n1].push_back({n2, cost});
    Edge[n2].push_back({n1, cost});
  }
}

void bfs()
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
      Visited[i][j] = INF;
  }

  Visited[1][0] = 0;

  queue<network> q;

  q.push({1, 0, 0});

  while (!q.empty())
  {
    int node = q.front().node;
    int cost = q.front().cost;
    int use_free = q.front().use_free;

    q.pop();

    if (cost >= Cost)
      continue;

    if (node == N)
    {
      Cost = min(cost, Cost);
      continue;
    }

    for (int i = 0; i < Edge[node].size(); i++)
    {
      int next_node = Edge[node][i].first;
      int next_cost = Edge[node][i].second;
      int max_cost = max(next_cost, cost);

      if (use_free < K)
      {
        if (Visited[next_node][use_free + 1] > cost)
        {
          Visited[next_node][use_free + 1] = cost;
          q.push({next_node, cost, use_free + 1});
        }
      }

      if (Visited[next_node][use_free] > max_cost)
      {
        Visited[next_node][use_free] = max_cost;
        q.push({next_node, max_cost, use_free});
      }
    }
  }

  if (Cost == INF)
    cout << -1 << '\n';
  else
    cout << Cost << '\n';
}
