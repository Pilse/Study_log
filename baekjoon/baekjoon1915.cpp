#include <iostream>
#include <string>

using namespace std;

void input();
void find_largest_square();
bool check_expandable(int r, int c, int width);

int R, C;
int Map[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  find_largest_square();
}

void input()
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    string str;

    cin >> str;

    for (int j = 0; j < C; j++)
      Map[i][j] = str[j] - '0';
  }
}

void find_largest_square()
{
  int largest_width = 0;

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (Map[i][j])
      {
        int width = 1;

        while (check_expandable(i, j, width + 1))
          ++width;

        largest_width = max(largest_width, width);

        if (largest_width == min(R, C))
        {
          cout << largest_width * largest_width << '\n';
          return;
        }
      }
    }
  }

  cout << largest_width * largest_width << '\n';
}

bool check_expandable(int r, int c, int width)
{
  for (int i = r; i < r + width; i++)
  {
    if (i >= R)
      return false;

    if (!Map[i][c + width - 1])
      return false;
  }

  for (int i = c; i < c + width; i++)
  {
    if (i >= C)
      return false;

    if (!Map[r + width - 1][i])
      return false;
  }

  return true;
}
