#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves)
{
  int answer = 0;
  int map_limit = board[0].size();
  stack<int> bucket;

  for (int i = 0; i < moves.size(); i++)
  {
    int row = 0;
    int column = moves[i] - 1;

    while (row < map_limit - 1)
    {
      if (board[row][column])
        break;
      row++;
    }

    int picked = board[row][column];
    board[row][column] = 0;

    if (!picked)
      continue;

    if (!bucket.empty() && (bucket.top() == picked))
    {
      bucket.pop();
      answer += 2;
    }
    else
    {
      bucket.push(picked);
    }
  }

  return answer;
}
