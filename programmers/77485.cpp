#include <string>
#include <vector>

using namespace std;

void update(int &prev, int &current, int &min_val)
{
  swap(prev, current);
  min_val = min(min_val, current);
}

int rotate(vector<int> query, vector<vector<int>> &map)
{
  int sy = query[0];
  int sx = query[1];
  int ey = query[2];
  int ex = query[3];

  int prev = map[sy][sx];
  int min_val = prev;

  for (int i = sx + 1; i <= ex; i++)
    update(prev, map[sy][i], min_val);
  for (int i = sy + 1; i <= ey; i++)
    update(prev, map[i][ex], min_val);
  for (int i = ex - 1; i >= sx; i--)
    update(prev, map[ey][i], min_val);
  for (int i = ey - 1; i >= sy; i--)
    update(prev, map[i][sx], min_val);

  return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
  vector<vector<int>> map(rows + 1, vector<int>(columns + 1));
  vector<int> answer;

  for (int i = 1; i <= rows; i++)
    for (int j = 1; j <= columns; j++)
      map[i][j] = (i - 1) * columns + j;

  for (vector<int> query : queries)
    answer.push_back(rotate(query, map));

  return answer;
}