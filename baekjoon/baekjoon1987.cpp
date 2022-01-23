#include <iostream>
#include <string>
#include <algorithm>

// A = 17
// Z = 42

using namespace std;

void input();
void dfs(int r, int c, int *visited, int step);

int R, C, Ans;
int Map[21][21];
int Visited[26];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, -1, 0, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  dfs(0, 0, Visited, 1);

  cout << Ans << '\n';
}

void input()
{
  cin >> R >> C;

  string temp;
  for (int i = 0; i < R; i++)
  {
    cin >> temp;

    for (int j = 0; j < C; j++)
      Map[i][j] = temp[j] - '0' - 17;
  }
}

void dfs(int r, int c, int *visited, int step)
{
  int cur_visited[26];

  copy(&visited[0], &visited[26], &cur_visited[0]);

  cur_visited[Map[r][c]] = 1;

  for (int i = 0; i < 4; i++)
  {
    int nr = r + Dr[i];
    int nc = c + Dc[i];

    if (nr < 0 || nc < 0 || nr >= R || nc >= C || cur_visited[Map[nr][nc]])
      continue;

    dfs(nr, nc, cur_visited, step + 1);
  }

  Ans = max(Ans, step);
}
