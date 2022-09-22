#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
  int r;
  int c;
  int step;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

pair<int, int> ctrl_move(vector<vector<int>> &board, int r, int c, int dir)
{
  while (1)
  {
    r += dr[dir];
    c += dc[dir];

    if (r < 0 || c < 0 || r >= 4 || c >= 4)
    {
      r -= dr[dir];
      c -= dc[dir];
      break;
    }

    if (board[r][c])
      break;
  }

  return {r, c};
}

int bfs(vector<vector<int>> &board, int &r, int &c, int target)
{
  int answer = 0;
  vector<vector<int>> visited(4, vector<int>(4, 0));

  queue<node> q;

  visited[r][c] = 1;
  q.push({r, c, 0});

  while (!q.empty())
  {
    int cur_r = q.front().r;
    int cur_c = q.front().c;
    int cur_step = q.front().step;
    q.pop();

    if (board[cur_r][cur_c] == target)
    {
      board[cur_r][cur_c] = 0;
      r = cur_r;
      c = cur_c;
      answer = cur_step + 1;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int next_r = cur_r + dr[i];
      int next_c = cur_c + dc[i];

      auto [ctrl_r, ctrl_c] = ctrl_move(board, cur_r, cur_c, i);

      if ((next_r != ctrl_r || next_c != ctrl_c) && !visited[ctrl_r][ctrl_c])
      {
        visited[ctrl_r][ctrl_c] = 1;
        q.push({ctrl_r, ctrl_c, cur_step + 1});
      }

      if (next_r < 0 || next_c < 0 || next_r >= 4 || next_c >= 4 || visited[next_r][next_c])
        continue;

      visited[next_r][next_c] = 1;
      q.push({next_r, next_c, cur_step + 1});
    }
  }

  return answer;
}

int solution(vector<vector<int>> board, int r, int c)
{
  vector<int> v(7, 0);
  vector<int> characters;

  for (int i = 0; i < board.size(); i++)
  {
    for (int j = 0; j < board[0].size(); j++)
    {
      if (board[i][j] && !v[board[i][j]])
      {
        v[board[i][j]] = 1;
        characters.push_back(board[i][j]);
      }
    }
  }

  sort(characters.begin(), characters.end());

  int answer = 1e8;
  do
  {
    int cnt = 0;
    int cur_r = r;
    int cur_c = c;

    vector<vector<int>> board_copied = board;

    for (auto ch : characters)
    {
      cnt += bfs(board_copied, cur_r, cur_c, ch);
      cnt += bfs(board_copied, cur_r, cur_c, ch);
    }

    answer = min(answer, cnt);

  } while (next_permutation(characters.begin(), characters.end()));

  return answer;
}
