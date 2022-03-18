#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

void input();
void game();
void bfs(int r, int c);
void remove_mineral(int dir, int height);
bool fall_mineral(int r, int c);

int R, C, N;
vector<int> Height;
char Map[101][101];
int Visited[101][101];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  game();
}

void input()
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> Map[i][j];

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int height;

    cin >> height;

    Height.push_back(height);
  }
}

void game()
{
  for (int t = 0; t < N; t++)
  {
    vector<pair<int, int> > cluster;

    memset(Visited, 0, sizeof(Visited));

    remove_mineral(t % 2, Height[t]);

    for (int i = 0; i < C; i++)
      if (Map[R - 1][i] == 'x' && !Visited[R - 1][i])
        bfs(R - 1, i);

    for (int i = R - 1; i >= 0; i--)
    {
      for (int j = 0; j < C; j++)
      {
        if (Map[i][j] == 'x' && !Visited[i][j])
        {
          cluster.push_back({i, j});
        }
      }
    }

    if (cluster.size() > 0)
    {
      bool touch_flag = true;

      while (touch_flag)
      {
        for (int i = 0; i < cluster.size(); i++)
        {
          touch_flag = touch_flag & fall_mineral(cluster[i].first, cluster[i].second);

          cluster[i].first++;
        }
      }
    }
  }

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cout << Map[i][j] << " ";
    }
    cout << '\n';
  }
}

void bfs(int r, int c)
{
  Visited[r][c] = 1;

  queue<pair<int, int> > q;

  q.push({r, c});

  while (!q.empty())
  {
    int cur_r = q.front().first;
    int cur_c = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int next_r = cur_r + Dr[i];
      int next_c = cur_c + Dc[i];

      if (next_r < 0 || next_c < 0 || next_c > C - 1 || next_r > R - 1)
        continue;

      if (Map[next_r][next_c] == 'x' && !Visited[next_r][next_c])
      {
        Visited[next_r][next_c] = 1;
        q.push({next_r, next_c});
      }
    }
  }
}

void remove_mineral(int dir, int height)
{
  if (dir == 0)
  {
    for (int i = 0; i < C; i++)
    {
      if (Map[R - height][i] == 'x')
      {
        Map[R - height][i] = '.';
        return;
      }
    }
  }

  else
  {
    for (int i = C - 1; i >= 0; i--)
    {
      if (Map[R - height][i] == 'x')
      {
        Map[R - height][i] = '.';
        return;
      }
    }
  }
}

bool fall_mineral(int r, int c)
{
  Map[r + 1][c] = 'x';
  Map[r][c] = '.';

  if (r + 2 >= R)
    return false;
  if (Map[r + 2][c] == 'x' && Visited[r + 2][c])
    return false;

  return true;
}
