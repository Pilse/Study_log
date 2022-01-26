#include <iostream>

using namespace std;

void input();
void recur(int r, int c, int n);
void pattern(int r, int c, int n);
void zero(int r, int c, int n);

int N;
char Map[6562][6562];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  recur(0, 0, N);

  for (int i = 0; i < N; i++)
    cout << Map[i] << '\n';
}

void input()
{
  cin >> N;
}

void recur(int r, int c, int n)
{
  if (n == 3)
  {
    pattern(r, c, n);
  }

  else
  {
    int step = n / 3;

    for (int i = 0; i < 9; i++)
    {
      int nr = r + i / 3 * step;
      int nc = c + i % 3 * step;

      if (i != 4)
        recur(nr, nc, step);
      else
        zero(nr, nc, step);
    }
  }
}

void pattern(int r, int c, int n)
{
  for (int i = r; i < r + n; i++)
  {
    for (int j = c; j < c + n; j++)
    {
      if (i == r + (n / 2) && j == c + (n / 2))
        Map[i][j] = ' ';

      else
        Map[i][j] = '*';
    }
  }
}

void zero(int r, int c, int n)
{
  for (int i = r; i < r + n; i++)
  {
    for (int j = c; j < c + n; j++)
    {
      Map[i][j] = ' ';
    }
  }
}
