#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

void find_crack();
void input();
void ice_decay();
void bfs(int r, int c);
int get_decay_cnt(int r, int c);

int R, C;
int Map[301][301];
int Visited[301][301];
int Dr[4] = {0, 1, 0, -1};
int Dc[4] = {1, 0, -1, 0};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  find_crack();
}

void input()
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> Map[i][j];
    }
  }
}

void find_crack()
{
  bool end_flag = false;
  int iter = 0;

  while (!end_flag)
  {
    memset(Visited, 0, sizeof(Visited));
    end_flag = true;

    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        if (Map[i][j] && !Visited[i][j])
        {
          if (!end_flag)
          {
            cout << iter << '\n';
            return;
          }

          else
          {
            end_flag = false;
            bfs(i, j);
          }
        }
      }
    }

    ice_decay();
    iter++;
  }

  cout << 0 << '\n';
}

void bfs(int r, int c)
{
  queue<pair<int, int> > q;

  q.push({r, c});

  Visited[r][c] = 1;

  while (!q.empty())
  {
    int cr = q.front().first;
    int cc = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = cr + Dr[i];
      int nc = cc + Dc[i];

      if (nr < 0 || nc < 0 || nr >= R || nc >= C || Visited[nr][nc] || !Map[nr][nc])
        continue;

      Visited[nr][nc] = 1;

      q.push({nr, nc});
    }
  }
}

void ice_decay()
{
  int update[301][301]{0};

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (Map[i][j])
      {
        int decay_cnt = get_decay_cnt(i, j);

        update[i][j] = max(0, Map[i][j] - decay_cnt);
      }
    }
  }

  copy(&update[0][0], &update[300][300], &Map[0][0]);
}

int get_decay_cnt(int r, int c)
{
  int decay_cnt = 0;

  for (int i = 0; i < 4; i++)
  {
    int nr = r + Dr[i];
    int nc = c + Dc[i];

    if (nr < 0 || nc < 0 || nr >= R || nc >= C)
      continue;

    if (!Map[nr][nc])
      decay_cnt++;
  }

  return decay_cnt;
}
