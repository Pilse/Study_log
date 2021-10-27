#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int P, C;
vector<int> v[101];
int visited[101];

int bfs(int num)
{
  queue<pair<int, int> > q;

  visited[num] = 1;

  q.push({num, 0});

  while (!q.empty())
  {
    int cur_n = q.front().first;
    int cur_cnt = q.front().second;
    q.pop();

    if (cur_n == P)
      return cur_cnt;

    for (int i = 0; i < v[cur_n].size(); i++)
    {
      int w = v[cur_n][i];

      if (!visited[w])
      {
        visited[w] = 1;
        q.push({w, cur_cnt + 1});
      }
    }
  }
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, t;
  int pt, pc;

  cin >> n;
  cin >> P >> C;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    cin >> pt >> pc;

    v[pt].push_back(pc);
    v[pc].push_back(pt);
  }

  cout << bfs(C) << '\n';
}
