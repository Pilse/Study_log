#include <iostream>
#include <vector>

struct coords
{
  int r;
  int c;
};

using namespace std;

int n, m;
vector<vector<int>> dp;
vector<coords> cases;

int calc(int p1, int p2);
void route(int p1, int p2);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  dp.resize(m + 1, vector<int>(m + 1, -1));
  cases.resize(m);
  for (auto &c : cases)
    cin >> c.r >> c.c;

  cout << calc(0, 0) << '\n';
  route(0, 0);
}

int calc(int p1, int p2)
{
  if (p1 == m || p2 == m)
    return 0;
  if (dp[p1][p2] != -1)
    return dp[p1][p2];

  int next = max(p1, p2) + 1;

  int d1 = p1 == 0
               ? abs(cases[next - 1].r - 1) + abs(cases[next - 1].c - 1)
               : abs(cases[next - 1].r - cases[p1 - 1].r) + abs(cases[next - 1].c - cases[p1 - 1].c);

  int d2 = p2 == 0
               ? abs(cases[next - 1].r - n) + abs(cases[next - 1].c - n)
               : abs(cases[next - 1].r - cases[p2 - 1].r) + abs(cases[next - 1].c - cases[p2 - 1].c);

  int r1 = d1 + calc(next, p2);
  int r2 = d2 + calc(p1, next);
  dp[p1][p2] = min(r1, r2);
  return dp[p1][p2];
}

void route(int p1, int p2)
{
  if (p1 == m || p2 == m)
    return;

  int next = max(p1, p2) + 1;

  int d1 = p1 == 0
               ? cases[next - 1].r - 1 + cases[next - 1].c - 1
               : abs(cases[next - 1].r - cases[p1 - 1].r) + abs(cases[next - 1].c - cases[p1 - 1].c);

  int d2 = p2 == 0
               ? abs(cases[next - 1].r - n) + abs(cases[next - 1].c - n)
               : abs(cases[next - 1].r - cases[p2 - 1].r) + abs(cases[next - 1].c - cases[p2 - 1].c);

  int r1 = dp[next][p2] + d1;
  int r2 = dp[p1][next] + d2;

  if (r1 < r2)
  {
    cout << 1 << '\n';
    route(next, p2);
  }
  else
  {
    cout << 2 << '\n';
    route(p1, next);
  }
}
