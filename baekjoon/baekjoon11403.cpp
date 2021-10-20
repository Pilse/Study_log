#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int arr[101][101];
int visited[101];
vector<int> v[101];

void bfs(int cur)
{
  queue<int> q;
  q.push(cur);

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
        arr[p][w] = 1;
        arr[cur][w] = 1;
        q.push(w);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, temp;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> temp;

      if (temp)
        v[i].push_back(j);
    }
  }

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      bfs(i);
      memset(visited, 0, sizeof(visited));
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
}
