#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
  int cost;
  int n1;
  int n2;
};

void input();
void init();
bool compare(Edge a, Edge b);
int find_parent(int n);
bool union_node(int x, int y);
void kruscal();

int N, C;
int Parent[2001];
vector<pair<int, int> > Node;
vector<Edge> Edge;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  init();

  sort(Edge.begin(), Edge.end(), compare);

  kruscal();
}

void input()
{
  cin >> N >> C;

  for (int i = 0; i < N; i++)
  {
    int x, y;

    cin >> x >> y;

    Node.push_back({x, y});
  }
}

void init()
{
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      int cost = (Node[i].first - Node[j].first) * (Node[i].first - Node[j].first) + (Node[i].second - Node[j].second) * (Node[i].second - Node[j].second);

      if (cost >= C)
        Edge.push_back({cost, i, j});
    }
  }

  for (int i = 0; i < N; i++)
    Parent[i] = i;
}

bool compare(struct Edge a, struct Edge b)
{
  return a.cost < b.cost;
}

void kruscal()
{
  int cnt = 0;
  int total_cost = 0;

  for (int i = 0; i < (int)Edge.size(); i++)
  {
    if (cnt == N - 1)
      break;

    if (union_node(Edge[i].n1, Edge[i].n2))
    {
      cnt++;
      total_cost += Edge[i].cost;
    }
  }

  if (cnt == N - 1)
    cout << total_cost << '\n';
  else
    cout << -1 << '\n';
}

int find_parent(int n)
{
  if (Parent[n] == n)
    return n;

  else
    return Parent[n] = find_parent(Parent[n]);
}

bool union_node(int x, int y)
{
  int p_x = find_parent(x);
  int p_y = find_parent(y);

  if (p_x == p_y)
    return false;

  if (p_x < p_y)
    swap(p_x, p_y);

  Parent[p_y] = p_x;

  return true;
}
