#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
  int answer = 0;
  int y_size = board.size();
  int x_size = board[0].size();
  vector<vector<int>> dp(y_size, vector<int>(x_size, 0));

  for (auto &s : skill)
  {
    int type = s[0] == 2 ? 1 : -1;
    int y1 = s[1];
    int x1 = s[2];
    int y2 = s[3];
    int x2 = s[4];
    int degree = s[5];

    dp[y1][x1] += type * degree;

    if (y2 + 1 < y_size && x2 + 1 < x_size)
      dp[y2 + 1][x2 + 1] += type * degree;
    if (y2 + 1 < y_size)
      dp[y2 + 1][x1] += -type * degree;
    if (x2 + 1 < x_size)
      dp[y1][x2 + 1] += -type * degree;
  }

  for (int i = 0; i < y_size; i++)
  {
    for (int j = 0; j < x_size; j++)
    {
      if (i - 1 < 0)
        dp[i][j] += dp[i][j - 1];
      else if (j - 1 < 0)
        dp[i][j] += dp[i - 1][j];
      else
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      if (board[i][j] + dp[i][j] > 0)
        answer++;
    }
  }

  return answer;
}

// -4 -1 0 0 1
// 2 0 -2 0 0
// -2 0 0 0 2
// 2 0 0 0 0

// -4 -5 -5 -5 -4
// -2 -3 -5 -5 -4
// -4 -5 -7 -7 -4
// -2 -3 -5 -5 -4