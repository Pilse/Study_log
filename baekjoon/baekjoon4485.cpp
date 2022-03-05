#include <iostream>
#include <queue>
#include <string.h>
#define INF 987654321

using namespace std;

void input();
void init();
int bfs();

int N;
int Map[126][126];
int Cost[126][126];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0;; i++)
  {
    init();

    input();

    if (N == 0)
      break;

    int min_cost = bfs();

    cout << "Problem " << i + 1 << ": " << min_cost << '\n';
  }
}

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> Map[i][j];
    }
  }
}

void init()
{
  memset(Map, 0, sizeof(Map));

  for (int i = 0; i < 126; i++)
  {
    for (int j = 0; j < 126; j++)
    {
      Cost[i][j] = INF;
    }
  }
}

int bfs()
{
  queue<pair<int, int> > q;

  Cost[0][0] = Map[0][0];

  q.push({0, 0});

  while (!q.empty())
  {
    int r = q.front().first;
    int c = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = r + Dr[i];
      int nc = c + Dc[i];

      if (nr < 0 || nc < 0 || nr >= N || nc >= N)
        continue;

      if (Cost[nr][nc] <= Cost[r][c] + Map[nr][nc])
        continue;

      Cost[nr][nc] = Cost[r][c] + Map[nr][nc];

      q.push({nr, nc});
    }
  }

  return Cost[N - 1][N - 1];
}
