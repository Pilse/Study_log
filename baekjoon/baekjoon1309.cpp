#include <iostream>
#include <string.h>

#define DIV 9901

using namespace std;

int dp[100000][3][2];
int n;

int zoo(int num, int dir, int zero)
{
  if (num == n)
  {
    if (zero == 1)
      return 0;
    return 1;
  }
  if (dp[num][dir][zero] != -1)
    return dp[num][dir][zero];

  if (dir == 0)
    return dp[num][dir][zero] = ((zoo(num + 1, 0, zero * 1)) % DIV + (zoo(num + 1, 1, zero * 0)) % DIV + (zoo(num + 1, 2, zero * 0) % DIV)) % DIV;
  if (dir == 1)
    return dp[num][dir][zero] = ((zoo(num + 1, 0, zero * 1)) % DIV + (zoo(num + 1, 2, zero * 0)) % DIV) % DIV;
  if (dir == 2)
    return dp[num][dir][zero] = ((zoo(num + 1, 0, zero * 1)) % DIV + (zoo(num + 1, 1, zero * 0)) % DIV) % DIV;

  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  memset(dp, -1, sizeof(dp));

  cout << zoo(0, 0, 1) + 1 << '\n';
}
