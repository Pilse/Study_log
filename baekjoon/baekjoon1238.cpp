#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct dest
{
  int target;
  int cost;
};

void input();
vector<int> dijkstra(int src);

int N, M, X;
int Ans = -1;
vector<dest> Map[1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  vector<int> dist_x = dijkstra(X);

  for (int i = 1; i <= N; i++)
  {
    if (i == X)
      continue;

    vector<int> dist_i = dijkstra(i);

    Ans = max(Ans, dist_i[X] + dist_x[i]);
  }

  cout << Ans << '\n';
}

void input()
{
  cin >> N >> M >> X;

  for (int i = 0; i < M; i++)
  {
    int s, t, c;

    cin >> s >> t >> c;

    Map[s].push_back({t, c});
  }
}

vector<int> dijkstra(int src)
{
  vector<int> dist(N + 1);
  priority_queue<pair<int, int> > pq;

  for (int i = 1; i <= N; i++)
    dist[i] = INF;

  dist[src] = 0;

  pq.push({0, src});

  while (!pq.empty())
  {
    int cost = -pq.top().first;
    int pos = pq.top().second;

    pq.pop();

    if (dist[pos] < cost)
      continue;

    for (int i = 0; i < Map[pos].size(); i++)
    {
      dest dest = Map[pos][i];

      if (dist[dest.target] > dist[pos] + dest.cost)
      {
        dist[dest.target] = dist[pos] + dest.cost;

        pq.push({-dist[dest.target], dest.target});
      }
    }
  }

  return dist;
}
