#include <vector>
#include <queue>

using namespace std;

void paint(int y, int x, vector<vector<int>> &picture, vector<vector<int>> &visited, int &max_size_of_one_area)
{
  int cnt = 0;
  int base_color = picture[y][x];
  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};

  visited[y][x] = 1;

  queue<pair<int, int>> q;
  q.push({y, x});

  while (!q.empty())
  {
    cnt++;

    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (ny < 0 || nx < 0 || ny >= picture.size() || nx >= picture[0].size())
        continue;
      if (picture[ny][nx] == base_color && !visited[ny][nx])
      {
        visited[ny][nx] = 1;
        q.push({ny, nx});
      }
    }
  }

  max_size_of_one_area = max(cnt, max_size_of_one_area);
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
  vector<vector<int>> visited(m, vector<int>(n, 0));
  int number_of_area = 0;
  int max_size_of_one_area = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (picture[i][j] && !visited[i][j])
      {
        paint(i, j, picture, visited, max_size_of_one_area);
        number_of_area++;
      }
    }
  }

  vector<int> answer(2);
  answer[0] = number_of_area;
  answer[1] = max_size_of_one_area;
  return answer;
}
