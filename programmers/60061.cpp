#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool can_build_column(vector<vector<int> > column_map, vector<vector<int> > beam_map, int x, int y)
{
  if (y == 0)
    return true;
  if (y - 1 >= 0 && column_map[x][y - 1] == 0)
    return true;
  if (beam_map[x][y] == 1)
    return true;
  if (x - 1 >= 0 && beam_map[x - 1][y] == 1)
    return true;
  return false;
}

bool can_build_beam(vector<vector<int> > column_map, vector<vector<int> > beam_map, int x, int y)
{
  int size = column_map.size() - 1;
  if (y - 1 >= 0 && column_map[x][y - 1] == 0)
    return true;
  if (y - 1 >= 0 && x + 1 <= size && column_map[x + 1][y - 1] == 0)
    return true;
  if (x - 1 >= 0 && x + 1 <= size && beam_map[x - 1][y] == 1 && beam_map[x + 1][y] == 1)
    return true;
  return false;
}

bool can_remove(vector<vector<int> > column_map, vector<vector<int> > beam_map, int x, int y, int a)
{
  if (a == 0)
    column_map[x][y] = -1;
  else
    beam_map[x][y] = -1;

  int size = column_map.size() - 1;

  for (int i = 0; i <= size; i++)
  {
    for (int j = 0; j <= size; j++)
    {
      if (column_map[i][j] == 0 && !can_build_column(column_map, beam_map, i, j))
        return false;
      if (beam_map[i][j] == 1 && !can_build_beam(column_map, beam_map, i, j))
        return false;
    }
  }

  return true;
}

bool compare(vector<int> a, vector<int> b)
{
  if (a[0] == b[0])
  {
    if (a[1] == b[1])
      return a[2] < b[2];
    return a[1] < b[1];
  }
  return a[0] < b[0];
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame)
{
  vector<vector<int> > column_map(n + 1, vector<int>(n + 1, -1));
  vector<vector<int> > beam_map(n + 1, vector<int>(n + 1, -1));
  vector<vector<int> > answer;

  for (int i = 0; i < build_frame.size(); i++)
  {
    int x = build_frame[i][0];
    int y = build_frame[i][1];
    int a = build_frame[i][2];
    int b = build_frame[i][3];

    if (b == 0)
    {
      if (can_remove(column_map, beam_map, x, y, a))
      {
        if (a == 1)
          beam_map[x][y] = -1;
        else
          column_map[x][y] = -1;
      }
    }
    else
    {
      if (a == 0 && can_build_column(column_map, beam_map, x, y))
        column_map[x][y] = a;
      else if (a == 1 && can_build_beam(column_map, beam_map, x, y))
        beam_map[x][y] = a;
    }
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (column_map[i][j] == 0)
      {
        vector<int> temp(3);
        temp[0] = i;
        temp[1] = j;
        temp[2] = 0;
        answer.push_back(temp);
      }
      if (beam_map[i][j] == 1)
      {
        vector<int> temp(3);
        temp[0] = i;
        temp[1] = j;
        temp[2] = 1;
        answer.push_back(temp);
      }
    }
  }

  sort(answer.begin(), answer.end(), compare);
  return answer;
}