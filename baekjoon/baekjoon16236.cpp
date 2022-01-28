#include <iostream>
#include <queue>

struct coor
{
  int r;
  int c;
};

struct path
{
  int distance;
  coor next_position;
};

using namespace std;

void Input();
void Game();
path Find_Shortest(coor position, int level);

int N, Level, Exp, Distance;
int Map[21][21];
int Dr[4] = {-1, 0, 0, 1};
int Dc[4] = {0, -1, 1, 0};
coor Start;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  Input();
  Game();

  cout << Distance << '\n';
}

void Input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> Map[i][j];

      if (Map[i][j] == 9)
        Start = {i, j};
    }
  }
}

void Game()
{
  Level = 1;

  coor position = Start;

  Map[position.r][position.c] = 0;

  while (1)
  {
    ++Level;
    Exp = 0;

    while (Exp != Level)
    {
      path route = Find_Shortest(position, Level);

      if (!route.distance)
        return;

      Distance += route.distance;

      position = route.next_position;

      Map[position.r][position.c] = 0;

      ++Exp;
    }
  }
}

path Find_Shortest(coor position, int level)
{
  int visited[21][21]{0};

  int min_step = 5000;
  coor min_pos;

  queue<pair<coor, int> > q;

  q.push({position, 0});

  visited[position.r][position.c] = 1;

  while (!q.empty())
  {
    coor cur = q.front().first;
    int step = q.front().second;

    q.pop();

    if (step > min_step)
      continue;

    if (Map[cur.r][cur.c] && Map[cur.r][cur.c] <= level - 1)
    {
      if (step < min_step)
      {
        min_step = step;
        min_pos = cur;
      }
      else if (step == min_step)
      {
        if (cur.r == min_pos.r)
        {
          if (cur.c < min_pos.c)
            min_pos = cur;
        }
        else if (cur.r < min_pos.r)
          min_pos = cur;
      }

      continue;
    }

    for (int i = 0; i < 4; i++)
    {
      int nr = cur.r + Dr[i];
      int nc = cur.c + Dc[i];

      if (nr < 0 || nc < 0 || nr >= N || nc >= N)
        continue;

      if (!visited[nr][nc] && Map[nr][nc] <= level)
      {
        visited[nr][nc] = 1;

        q.push({{nr, nc}, step + 1});
      }
    }
  }

  if (min_step == 5000)
    return {0, min_pos};

  else
    return {min_step, min_pos};
}
