#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct coor
{
  int x;
  int y;
};

void input();
void dragon(int x, int y, int d, int g);

int Map[101][101];
int Dx[4] = {1, 0, -1, 0};
int Dy[4] = {0, -1, 0, 1};
int Tot;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  for (int i = 0; i < 100; i++)
  {
    for (int j = 0; j < 100; j++)
    {
      if (Map[i][j] && Map[i + 1][j] && Map[i][j + 1] && Map[i + 1][j + 1])
        Tot++;
    }
  }

  cout << Tot << '\n';
}

void input()
{
  int tc, x, y, d, g;

  cin >> tc;

  while (tc--)
  {
    cin >> x >> y >> d >> g;
    dragon(x, y, d, g);
  }
}

void dragon(int x, int y, int d, int g)
{
  vector<coor> vec;

  vec.push_back({x, y});
  vec.push_back({x + Dx[d], y + Dy[d]});

  Map[y][x] = 1;
  Map[y + Dy[d]][x + Dx[d]] = 1;

  for (int t = 0; t < g; t++)
  {
    int last = pow(2, t);
    int lx = vec[last].x;
    int ly = vec[last].y;

    for (int i = last - 1; i >= 0; i--)
    {
      int tx = vec[i].x;
      int ty = vec[i].y;

      int diff_x = abs(lx - tx);
      int diff_y = abs(ly - ty);

      int nx;
      int ny;

      if (tx > lx && ty >= ly)
      {
        nx = lx - diff_y;
        ny = ly + diff_x;
      }
      else if (tx <= lx && ty < ly)
      {
        nx = lx + diff_y;
        ny = ly - diff_x;
      }
      else if (tx > lx && ty < ly)
      {
        nx = lx + diff_y;
        ny = ly + diff_x;
      }
      else
      {
        nx = lx - diff_y;
        ny = ly - diff_x;
      }

      vec.push_back({nx, ny});
      Map[ny][nx] = 1;
    }
  }
}
