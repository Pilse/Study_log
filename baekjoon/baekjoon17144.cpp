#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct coor
{
  int r;
  int c;
};

int R, C, T;
int map[52][52];
int sub_map[52][52];
vector<coor> vec;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool is_cleaner(int r, int c);
void spread();
void rotate();
void copy_map();

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tot = 0;

  cin >> R >> C >> T;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
    {
      cin >> map[i][j];

      if (map[i][j] == -1)
        vec.push_back({i, j});
    }

  while (T--)
  {
    spread();
    copy_map();
    rotate();
    copy_map();

    memset(sub_map, 0, sizeof(sub_map));
  }

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      if (map[i][j] > 0)
        tot += map[i][j];

  cout << tot << '\n';
}

bool is_cleaner(int r, int c)
{
  for (int i = 0; i < 2; i++)
  {
    if (vec[i].r == r && vec[i].c == c)
      return true;
  }

  return false;
}

void spread()
{
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (map[i][j] > 0)
      {
        sub_map[i][j] += map[i][j];

        int amount = map[i][j] / 5;

        for (int k = 0; k < 4; k++)
        {
          int ni = i + dr[k];
          int nj = j + dc[k];

          if (ni < 0 || nj < 0 || ni >= R || nj >= C || is_cleaner(ni, nj))
            continue;

          sub_map[ni][nj] += amount;
          sub_map[i][j] -= amount;
        }
      }
    }
  }
}

void rotate()
{
  for (int i = 0; i < 2; i++)
  {
    int cr = vec[i].r;
    int cc = vec[i].c;

    if (i == 1)
    {
      for (int j = cc + 1; j < C - 1; j++)
        sub_map[cr][j + 1] = map[cr][j];

      for (int j = cr - 1; j > 0; j--)
        sub_map[j - 1][C - 1] = map[j][C - 1];

      for (int j = C - 1; j > 0; j--)
        sub_map[0][j - 1] = map[0][j];

      for (int j = 0; j < cr - 1; j++)
        sub_map[j + 1][cc] = map[j][cc];
    }

    else
    {
      for (int j = cc + 1; j < C - 1; j++)
        sub_map[cr][j + 1] = map[cr][j];

      for (int j = cr + 1; j < R - 1; j++)
        sub_map[j + 1][C - 1] = map[j][C - 1];

      for (int j = C - 1; j > 0; j--)
        sub_map[R - 1][j - 1] = map[R - 1][j];

      for (int j = R - 1; j > cr + 1; j--)
        sub_map[j - 1][cc] = map[j][cc];
    }
  }
  sub_map[vec[0].r][vec[0].c + 1] = 0;
  sub_map[vec[1].r][vec[1].c + 1] = 0;
  sub_map[vec[0].r][vec[0].c] = -1;
  sub_map[vec[1].r][vec[1].c] = -1;
}

void copy_map()
{
  copy(&sub_map[0][0], &sub_map[0][0] + 52 * 52, &map[0][0]);
}
