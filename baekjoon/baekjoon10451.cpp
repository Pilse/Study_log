#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int visited[1001];

int cycle(int n, vector<int> v[1001])
{
  int parent = n;
  int cur = n;

  queue<int> q;
  q.push(n);

  while (!q.empty())
  {
    int p = q.front();
    cur = p;

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
  if (parent == cur)
    return 1;
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n, temp, cnt = 0;
    vector<int> v[1001];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
      cin >> temp;
      v[i].push_back(temp);
    }

    for (int i = 1; i <= n; i++)
    {
      if (!visited[i])
        cnt += cycle(i, v);
    }

    cout << cnt << '\n';

    fill(visited, visited + 1001, 0);
    //        memset(visited, 0, sizeof(visited));
  }
}
