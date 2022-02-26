#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct coor
{
  int r;
  int c;
  int cost;
};

void input();
void bfs();

int N;
int Map[51][51];
int Visited[51][51];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  bfs();
}

void input()
{
  cin >> N;

  string str;

  for (int i = 0; i < N; i++)
  {
    cin >> str;

    for (int j = 0; j < N; j++)
    {
      if (str[j] == '1')
        Map[i][j] = 1;
      else
        Map[i][j] = 0;
    }
  }
}

void bfs()
{
  Visited[0][0] = 1;

  deque<coor> dq;

  dq.push_back({0, 0, 0});

  while (!dq.empty())
  {
    int r = dq.front().r;
    int c = dq.front().c;
    int cost = dq.front().cost;

    dq.pop_front();

    if (r == N - 1 && c == N - 1)
    {
      cout << cost << '\n';
      return;
    }

    for (int i = 0; i < 4; i++)
    {
      int nr = r + Dr[i];
      int nc = c + Dc[i];

      if (nr < 0 || nc < 0 || nr >= N || nc >= N || Visited[nr][nc])
        continue;

      Visited[nr][nc] = 1;

      if (Map[nr][nc] == 1)
        dq.push_front({nr, nc, cost});
      else
        dq.push_back({nr, nc, cost + 1});
    }
  }
}
