#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[501];
int visited[501];

int bfs(int n)
{
  queue<pair<int, int> > q;
  int cnt = -1;

  visited[n] = 1;

  q.push({n, 0});

  while (!q.empty())
  {
    int p = q.front().first;
    int d = q.front().second;
    q.pop();

    if (d > 2)
      continue;

    cnt++;

    for (int i = 0; i < v[p].size(); i++)
    {
      int w = v[p][i];

      if (!visited[w])
      {
        visited[w] = 1;
        q.push({w, d + 1});
      }
    }
  }

  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int m;
  int t1, t2;

  cin >> n;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> t1 >> t2;
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }

  cout << bfs(1) << '\n';
}
