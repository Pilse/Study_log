#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
  int r;
  int c;
  int cost;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(vector<vector<int> > board)
{
  int visited[26][26][4]{0};
  int map_size = board[0].size();
  int shortest = 450000;

  queue<pair<node, int> > q;

  q.push({{0, 0, 0}, -1});

  while (!q.empty())
  {
    node cur = q.front().first;
    int dir = q.front().second;

    q.pop();

    if (cur.r == map_size - 1 && cur.c == map_size - 1)
    {
      shortest = min(shortest, cur.cost);
      continue;
    }

    for (int i = 0; i < 4; i++)
    {
      int nr = cur.r + dr[i];
      int nc = cur.c + dc[i];
      int ncost = cur.cost;

      if (dir == -1)
        ncost = 100;
      else
        ncost = dir == i ? cur.cost + 100 : cur.cost + 600;

      if (nr < 0 || nc < 0 || nr >= map_size || nc >= map_size)
        continue;
      if (board[nr][nc] == 1)
        continue;

      if (!visited[nr][nc][i] || visited[nr][nc][i] > ncost)
      {
        visited[nr][nc][i] = ncost;
        q.push({{nr, nc, ncost}, i});
      }
    }
  }

  return shortest;
}

int solution(vector<vector<int> > board)
{
  int answer = bfs(board);

  return answer;
}