#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int dp[203][102];
int k;
string str;

int combination(int n, int r)
{
  if (n == 0 || r == 0)
    return 1;
  if (dp[n][r] != -1)
    return dp[n][r];

  return dp[n][r] = min(combination(n - 1, r) + combination(n, r - 1), 1000000001);
}

void get_word(int n, int m, int cnt)
{
  if (n == 0)
  {
    for (int i = 0; i < m; i++)
      str += 'z';
    return;
  }
  if (m == 0)
  {
    for (int i = 0; i < n; i++)
      str += 'a';
    return;
  }

  int next_cnt = combination(n - 1, m);
  //    cout << cnt << " " << next_cnt << '\n';
  if (cnt < next_cnt)
  {
    str += 'a';
    get_word(n - 1, m, cnt);
  }
  else
  {
    str += 'z';
    get_word(n, m - 1, cnt - next_cnt);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m >> k;

  memset(dp, -1, sizeof(dp));
  int c = combination(n, m);
  if (c < k)
  {
    cout << -1 << '\n';
    return 0;
  }

  get_word(n, m, k - 1);
  cout << str << '\n';
}
