#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

struct coor
{
  double x;
  double y;
};

double get_distance(coor src, coor trg);
void input();
void init();
void dijkstra();

coor Src, Trg;
int Num;
vector<coor> Nodes;
vector<pair<int, double> > Costs[101];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  init();

  dijkstra();
}

void input()
{
  cin >> Src.x >> Src.y;

  cin >> Trg.x >> Trg.y;

  Nodes.push_back(Src);

  cin >> Num;

  for (int i = 0; i < Num; i++)
  {
    coor temp;

    cin >> temp.x >> temp.y;

    Nodes.push_back(temp);
  }

  Nodes.push_back(Trg);
}

double get_distance(coor src, coor trg)
{
  double sqare_x = (src.x - trg.x) * (src.x - trg.x);
  double sqare_y = (src.y - trg.y) * (src.y - trg.y);

  return sqrt(sqare_x + sqare_y);
}

void init()
{
  for (int i = 1; i <= Num + 1; i++)
    Costs[0].push_back({i, get_distance(Nodes[0], Nodes[i]) / 5});

  for (int i = 1; i <= Num; i++)
  {
    for (int j = 1; j <= Num + 1; j++)
    {
      if (i == j)
        continue;

      double node_distance = get_distance(Nodes[i], Nodes[j]);

      Costs[i].push_back({j, min(node_distance / 5, 2 + abs(node_distance - 50) / 5)});
    }
  }
}

void dijkstra()
{
  priority_queue<pair<double, int> > pq;

  double dist[Num + 2];

  dist[0] = 0;

  for (int i = 1; i <= Num + 1; i++)
    dist[i] = INF;

  pq.push({0, 0});

  while (!pq.empty())
  {
    double cost = -pq.top().first;
    int node = pq.top().second;

    pq.pop();

    if (dist[node] < cost)
      continue;

    for (int i = 0; i < Costs[node].size(); i++)
    {
      int next_node = Costs[node][i].first;
      double next_cost = Costs[node][i].second;

      if (dist[next_node] > cost + next_cost)
      {
        dist[next_node] = cost + next_cost;

        pq.push({-(cost + next_cost), next_node});
      }
    }
  }

  cout << dist[Num + 1] << '\n';
}
