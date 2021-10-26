#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];
int visited[101];

int bfs(int num)
{
  queue<pair<int, int> > q;
  int res = 0;

  visited[num] = 1;

  q.push({num, 0});

  while (!q.empty())
  {
    int cur_user = q.front().first;
    int cur_bri = q.front().second;
    q.pop();

    res += cur_bri;

    for (int i = 0; i < v[cur_user].size(); i++)
    {
      int w = v[cur_user][i];

      if (!visited[w])
      {
        visited[w] = 1;
        q.push({w, cur_bri + 1});
      }
    }
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, t1, t2;
  int kevin;
  int user_num;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> t1 >> t2;
    v[t1].push_back(t2);
    v[t2].push_back(t1);
  }

  kevin = bfs(1);
  user_num = 1;
  fill(&visited[0], &visited[100], 0);

  for (int i = 2; i <= n; i++)
  {
    int res = bfs(i);
    if (res < kevin)
    {
      kevin = res;
      user_num = i;
    }

    fill(&visited[0], &visited[100], 0);
  }

  cout << user_num << '\n';
}
