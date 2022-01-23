#include <iostream>
#include <vector>

using namespace std;

void input();
void gobang();
int is_winning_condition(int r, int c);

int R = 19, C = 19;
int Map[20][20];
vector<pair<int, int> > Vec;
int Dr[4] = {0, 1, 1, 1};
int Dc[4] = {1, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  gobang();
}

void input()
{
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin >> Map[i][j];

      if (Map[i][j] > 0)
        Vec.push_back({i, j});
    }
  }
}

void gobang()
{
  for (int t = 0; t < Vec.size(); t++)
  {
    int r = Vec[t].first;
    int c = Vec[t].second;

    int condition = is_winning_condition(r, c);

    if (condition == 1)
    {
      cout << Map[r][c] << '\n';

      cout << r + 1 << " " << c + 1 << '\n';

      return;
    }

    else if (condition == 3)
    {
      cout << Map[r][c] << '\n';

      cout << r + 1 + Dr[3] * 4 << " " << c + 1 + Dc[3] * 4 << '\n';

      return;
    }
  }

  cout << 0 << '\n';
}

int is_winning_condition(int r, int c)
{
  int color = Map[r][c];

  for (int i = 0; i < 4; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      int nr = r + Dr[i] * j;
      int nc = c + Dc[i] * j;

      if (nr < 0 || nc < 0 || nr >= R || nc >= C || Map[nr][nc] != color)
        break;

      if (j == 4)
      {
        int pr = r - Dr[i];
        int pc = c - Dc[i];

        if (!(pr < 0 || pc < 0 || pr >= R || pc >= C))
          if (Map[pr][pc] == color)
            break;

        pr = r + Dr[i] * 5;
        pc = c + Dc[i] * 5;

        if (!(pr < 0 || pc < 0 || pr >= R || pc >= C))
          if (Map[pr][pc] == color)
            break;

        if (i == 3)
          return 3;
        return 1;
      }
    }
  }

  return 0;
}
