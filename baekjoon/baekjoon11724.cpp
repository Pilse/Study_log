#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1001];
int visited[1001];

void bfs(int num)
{
  queue<int> q;

  visited[num] = 1;

  q.push(num);

  while (!q.empty())
  {
    int p = q.front();
    q.pop();

    for (int i = 0; i < v[p].size(); i++)
    {
      int w = v[p][i];

      if (!visited[w])
      {
        visited[w] = 1;
        q.push(w);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  int t1, t2;
  int cnt = 0;

  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> t1 >> t2;
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      bfs(i);
      cnt++;
    }
  }

  cout << cnt << '\n';
}
