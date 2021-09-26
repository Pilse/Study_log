#include <iostream>
#include <cstring>

using namespace std;

int n;
long long dp[31][31];

long long med(int w, int h)
{
  if (w > n || h > w)
    return 0;

  if (dp[w][h] != -1)
    return dp[w][h];

  if (w == n && h == n)
    return 1;

  return dp[w][h] = med(w + 1, h) + med(w, h + 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  while (n)
  {
    memset(dp, -1, sizeof(dp));
    cout << med(1, 0) << '\n';
    cin >> n;
  }
}
