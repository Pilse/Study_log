#include <iostream>
#include <vector>

using namespace std;

class Tetris
{
private:
  vector<vector<int>> m;
  int max_row;
  int max_col;
  int score;

public:
  Tetris()
  {
    max_row = 6;
    max_col = 4;
    score = 0;
    m.resize(max_row, vector<int>(max_row - 2, 0));
  }
  void move_block(int type, int r, int c);
  bool check_line_full(int line);
  bool check_line_one(int line);
  void erase_line(int line);
  void move_lines(int from, int to);
  int get_num_of_block(int from, int to);
  void up_score();
  int get_score();
  void print();
};

void Tetris::move_block(int type, int r, int c)
{
  int cur_r = r;
  int cur_c = c;
  if (type == 1)
  {
    while (cur_r != max_row - 1)
    {
      if (m[cur_r + 1][cur_c] == 1)
        break;
      cur_r++;
    }
    m[cur_r][cur_c] = 1;
    return;
  }
  if (type == 2)
  {
    while (cur_r != max_row - 1)
    {
      if (m[cur_r + 1][cur_c] == 1 || m[cur_r + 1][cur_c + 1] == 1)
        break;
      cur_r++;
    }
    m[cur_r][cur_c] = 1;
    m[cur_r][cur_c + 1] = 1;
    return;
  }
  while (cur_r != max_row - 2)
  {
    if (m[cur_r + 2][cur_c] == 1)
      break;
    cur_r++;
  }
  m[cur_r][cur_c] = 1;
  m[cur_r + 1][cur_c] = 1;
}

bool Tetris::check_line_full(int line)
{
  for (int i = 0; i < max_col; i++)
    if (!m[line][i])
      return false;
  return true;
}

bool Tetris::check_line_one(int line)
{
  for (int i = 0; i < max_col; i++)
    if (m[line][i])
      return true;
  return false;
}

void Tetris::erase_line(int line)
{
  for (int i = 0; i < max_col; i++)
    m[line][i] = 0;
}

void Tetris::move_lines(int from, int to)
{
  for (int i = to; i >= from; i--)
    for (int j = 0; j < max_col; j++)
      m[i + 1][j] = m[i][j];
  erase_line(from);
}

int Tetris::get_num_of_block(int from, int to)
{
  int cnt = 0;
  for (int i = 2; i < max_row; i++)
    for (int j = 0; j < max_col; j++)
      if (m[i][j])
        cnt++;
  return cnt;
}

void Tetris::up_score()
{
  score++;
}

int Tetris::get_score()
{
  return score;
}

void Tetris::print()
{
  for (int i = 0; i < max_row; i++)
  {
    for (int j = 0; j < max_col; j++)
    {
      cout << m[i][j] << " ";
    }
    cout << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  Tetris green;
  Tetris blue;

  while (n--)
  {
    int type, r, c;
    cin >> type >> r >> c;

    green.move_block(type, 0, c);
    if (type == 1)
      blue.move_block(1, 0, 3 - r);
    if (type == 2)
      blue.move_block(3, 0, 3 - r);
    if (type == 3)
      blue.move_block(2, 0, 3 - r - 1);

    for (int i = 5; i >= 2; i--)
    {
      if (!green.check_line_full(i))
        continue;

      green.erase_line(i);
      green.move_lines(0, i - 1);
      green.up_score();
      i++;
    }
    for (int i = 5; i >= 2; i--)
    {
      if (!blue.check_line_full(i))
        continue;

      blue.erase_line(i);
      blue.move_lines(0, i - 1);
      blue.up_score();
      i++;
    }

    for (int i = 1; i >= 0; i--)
    {
      if (!green.check_line_one(i))
        continue;

      green.erase_line(5);
      green.move_lines(0, 4);
      i++;
    }
    for (int i = 1; i >= 0; i--)
    {
      if (!blue.check_line_one(i))
        continue;

      blue.erase_line(5);
      blue.move_lines(0, 4);
      i++;
    }
  }

  int tot_score = green.get_score() + blue.get_score();
  int tot_blocks = green.get_num_of_block(0, 5) + blue.get_num_of_block(0, 5);

  cout << tot_score << '\n'
       << tot_blocks << '\n';
}
