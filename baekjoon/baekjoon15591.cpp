#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

void input();
void bfs(int n, int limit);
void answer();

int N, Q;
int Map[5001][5001];
vector<pair<int, int> > Net[5001];
vector<pair<int, int> > Question;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  answer();
}

void input()
{
  cin >> N >> Q;

  for (int i = 0; i < N - 1; i++)
  {
    int n1, n2, usado;

    cin >> n1 >> n2 >> usado;

    Net[n1].push_back({n2, usado});
    Net[n2].push_back({n1, usado});

    Map[n1][n2] = usado;
    Map[n2][n1] = usado;
  }

  for (int i = 0; i < Q; i++)
  {
    int k, v;

    cin >> k >> v;

    Question.push_back({k, v});
  }
}

void bfs(int n, int limit)
{
  int dist[5001];
  int visited[5001]{0};
  queue<pair<int, int> > q;

  for (int i = 1; i <= N; i++)
  {
    dist[i] = INF;
  }

  visited[n] = 0;

  q.push({n, INF});

  while (!q.empty())
  {
    int cur = q.front().first;
    int usado = q.front().second;

    q.pop();

    if (Map[n][cur])
      dist[cur] = Map[n][cur];
    else
      dist[cur] = min(dist[cur], usado);

    for (int i = 0; i < Net[cur].size(); i++)
    {
      int next = Net[cur][i].first;
      int next_usado = Net[cur][i].second;

      if (!visited[next])
      {
        visited[next] = next_usado;
        q.push({next, min(usado, next_usado)});
      }
    }
  }

  int cnt = 0;

  for (int i = 1; i <= N; i++)
  {
    if (i == n)
      continue;

    if (dist[i] >= limit)
      cnt++;
  }

  cout << cnt << '\n';
}

void answer()
{
  for (int i = 0; i < Question.size(); i++)
  {
    int k = Question[i].first;
    int v = Question[i].second;

    bfs(v, k);
  }
}
