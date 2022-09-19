#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#define BLACK 201

using namespace std;

struct rectangle
{
  int minr;
  int maxr;
  int minc;
  int maxc;
  rectangle() : minr(51), minc(51), maxr(-1), maxc(-1) {}
};

void fill_black(vector<vector<int>> &board)
{
  int row = board.size();
  int column = board[0].size();

  for (int c = 0; c < column; c++)
  {
    for (int r = 0; r < row; r++)
    {
      if (board[r][c] && board[r][c] != BLACK)
        break;
      board[r][c] = BLACK;
    }
  }
}

rectangle get_rectangle(vector<vector<int>> board, int r, int c)
{
  int row = board.size();
  int column = board[0].size();
  int base = board[r][c];
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, 1, 0, -1};
  int visited[row][column];
  rectangle pos;

  memset(visited, 0, sizeof(visited));

  queue<pair<int, int>> q;
  q.push({r, c});
  pos.minr = r;
  pos.maxr = r;
  pos.minc = c;
  pos.maxc = c;
  visited[r][c] = 1;

  while (!q.empty())
  {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];
      if (nr >= row || nc >= column || nr < 0 || nc < 0)
        continue;
      if (visited[nr][nc])
        continue;
      if (board[nr][nc] == base)
      {
        pos.minr = min(pos.minr, nr);
        pos.minc = min(pos.minc, nc);
        pos.maxr = max(pos.maxr, nr);
        pos.maxc = max(pos.maxc, nc);
        visited[nr][nc] = 1;
        q.push({nr, nc});
      }
    }
  }
  return pos;
}

bool check_filled(vector<vector<int>> board, rectangle pos, int base)
{
  for (int r = pos.minr; r <= pos.maxr; r++)
  {
    for (int c = pos.minc; c <= pos.maxc; c++)
    {
      if (!(board[r][c] == base || board[r][c] == BLACK))
        return false;
    }
  }
  return true;
}

void remove_rectangle(vector<vector<int>> &board, rectangle pos)
{
  for (int r = pos.minr; r <= pos.maxr; r++)
  {
    for (int c = pos.minc; c <= pos.maxc; c++)
    {
      board[r][c] = 0;
    }
  }
}

int solution(vector<vector<int>> board)
{
  int score = 0;
  bool game_continue = true;
  int row = board.size();
  int column = board[0].size();

  while (game_continue)
  {
    game_continue = false;

    fill_black(board);

    for (int r = 0; r < row; r++)
    {
      for (int c = 0; c < column; c++)
      {
        if (board[r][c] && board[r][c] < BLACK)
        {
          rectangle pos = get_rectangle(board, r, c);
          int base = board[r][c];
          if (check_filled(board, pos, base))
          {
            score++;
            game_continue = true;
            remove_rectangle(board, pos);
          }
        }
      }
    }
  }
  return score;
}