#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

void input();
int bfs(int s);

int N, M;
vector<int> Vec[10001];
vector<pair<int, int> > Ans;
int Visited[10001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  for (int i = 1; i <= N; i++)
  {
    int cnt = bfs(i);

    if (Ans.size() == 0 || cnt == Ans[0].second)
      Ans.push_back({i, cnt});

    else if (cnt > Ans[0].second)
    {
      vector<pair<int, int> >(0).swap(Ans);

      Ans.push_back({i, cnt});
    }
  }

  for (int i = 0; i < Ans.size(); i++)
    cout << Ans[i].first << " ";
  cout << '\n';
}

void input()
{
  cin >> N >> M;

  int a, b;

  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    Vec[b].push_back(a);
  }
}

int bfs(int s)
{
  int cnt = 1;
  queue<int> q;
  memset(Visited, 0, sizeof(Visited));

  Visited[s] = 1;

  q.push(s);

  while (!q.empty())
  {
    int p = q.front();

    q.pop();

    for (int i = 0; i < Vec[p].size(); i++)
    {
      int w = Vec[p][i];

      if (!Visited[w])
      {
        Visited[w] = 1;
        cnt++;

        q.push(w);
      }
    }
  }

  return cnt;
}
