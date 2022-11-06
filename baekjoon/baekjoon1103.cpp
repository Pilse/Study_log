#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string.h>

using namespace std;

struct node
{
  int r;
  int c;
  int cnt;
};

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int r, c;
vector<vector<int>> visited;
vector<vector<int>> dp;
vector<vector<char>> g;

int dfs(int cr, int cc)
{
  if (cr < 0 || cc < 0 || cr >= r || cc >= c || g[cr][cc] == 'H')
    return 0;
  if (visited[cr][cc])
  {
    cout << -1 << '\n';
    exit(0);
  }

  if (dp[cr][cc] != -1)
    return dp[cr][cc];
  int amount = g[cr][cc] - '0';

  visited[cr][cc] = 1;
  dp[cr][cc] = 0;
  for (int i = 0; i < 4; i++)
  {
    int nr = cr + dr[i] * amount;
    int nc = cc + dc[i] * amount;
    dp[cr][cc] = max(dp[cr][cc], dfs(nr, nc) + 1);
  }
  visited[cr][cc] = 0;
  return dp[cr][cc];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c;
  g.resize(r);

  for (int i = 0; i < r; i++)
  {
    string str;
    cin >> str;

    copy(str.begin(), str.end(), back_inserter(g[i]));
  }

  visited.resize(r, vector<int>(c, 0));
  dp.resize(r, vector<int>(c, -1));

  cout << dfs(0, 0) << '\n';
}
