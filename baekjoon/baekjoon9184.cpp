#include <iostream>
#include <cstring>

using namespace std;

int dp[105][105][105];

int func(int a, int b, int c)
{
  if (a <= 0 || b <= 0 || c <= 0)
    return 1;

  int &res = dp[a][b][c];

  if (res != -1)
    return res;

  if (a > 20 || b > 20 || c > 20)
    return res = func(20, 20, 20);
  else if (a < b && b < c)
    return res = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
  else
    return res = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c;

  cin >> a >> b >> c;
  memset(dp, -1, sizeof(dp));

  while (!(a == -1 && b == -1 && c == -1))
  {
    cout << "w(" << a << ", " << b << ", " << c << ") = " << func(a, b, c) << '\n';
    cin >> a >> b >> c;
  }
}
