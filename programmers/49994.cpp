#include <string>
#include <iostream>

using namespace std;

pair<int, int> command(char c)
{
  if (c == 'U')
    return {-1, 0};
  if (c == 'D')
    return {1, 0};
  if (c == 'R')
    return {0, 1};
  if (c == 'L')
    return {0, -1};
  return {0, 0};
}

int solution(string dirs)
{
  int map[11][11]{0};
  int visited[11][11][11][11]{0};
  int cnt = 0;
  pair<int, int> pos = {5, 5};

  for (int i = 0; i < dirs.length(); i++)
  {
    char dir = dirs[i];
    pair<int, int> cmd = command(dir);
    pair<int, int> npos = {pos.first + cmd.first, pos.second + cmd.second};

    if (npos.first < 0 || npos.second < 0 || npos.first > 10 || npos.second > 10)
      continue;

    if (!visited[pos.first][pos.second][npos.first][npos.second] && !visited[npos.first][npos.second][pos.first][pos.second])
    {
      cnt++;
      visited[pos.first][pos.second][npos.first][npos.second] = 1;
      visited[npos.first][npos.second][pos.first][pos.second] = 1;
    }

    pos.first = npos.first;
    pos.second = npos.second;
  }

  return cnt;
}