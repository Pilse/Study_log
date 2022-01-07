#include <iostream>

using namespace std;

void input();
void clean(int r, int c, int d);

int R, C, RobotR, RobotC, RobotD, Tot;
int Map[52][52];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  clean(RobotR, RobotC, RobotD);

  cout << Tot << '\n';
}

void input()
{
  cin >> R >> C;

  cin >> RobotR >> RobotC >> RobotD;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> Map[i][j];
}

void clean(int r, int c, int d)
{
  if (!Map[r][c])
    Tot++;

  Map[r][c] = 2;

  for (int i = 1; i <= 4; i++)
  {
    int nd = d - i >= 0 ? d - i : 4 - i + d;
    int nr = r + Dr[nd];
    int nc = c + Dc[nd];

    if (nr < 0 || nc < 0 || nr >= R || nc >= C || Map[nr][nc])
      continue;

    clean(nr, nc, nd);

    return;
  }

  int br = r - Dr[d];
  int bc = c - Dc[d];

  if (br < 0 || bc < 0 || br >= R || bc >= C)
    return;
  if (Map[br][bc] == 2)
    clean(br, bc, d);
}
