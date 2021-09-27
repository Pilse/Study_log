#include <iostream>
#include <cstring>

using namespace std;

long long dp[101][101][2];
int n, k;

long long bit_cnt(int cn, int ck, int prev)
{
  //    cout << cn << " " << ck << " " << prev << '\n';
  if (cn == 0)
  {
    if (ck == 0)
    {
      return 1;
    }
    return 0;
  }

  if (dp[cn][ck][prev] != -1)
    return dp[cn][ck][prev];

  int nk = ck;
  if (prev)
    nk--;

  return dp[cn][ck][prev] = bit_cnt(cn - 1, ck, 0) + bit_cnt(cn - 1, nk, 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;

  cin >> t;
  memset(dp, -1, sizeof(dp));

  while (t--)
  {

    cin >> n >> k;

    cout << bit_cnt(n, k, 0) << '\n';
  }
}
