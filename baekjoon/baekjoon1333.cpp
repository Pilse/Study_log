// n
// l . . . . . . x x x x x . . . . .
// d . x x x x x x .
#include <iostream>

using namespace std;

int sing[4000];
int ring[4000];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, l, d;
  cin >> n >> l >> d;

  for (int i = 0; i < n; i++)
  {
    int base = i * (l + 5);
    for (int j = 0; j < l; j++)
      sing[base + j] = 1;
  }

  for (int i = 0; i <= l + (n - 1) * (l + 5); i++)
  {
    if (i % d == 0)
    {
      if (!sing[i])
      {
        cout << i << '\n';
        return 0;
      }
    }
  }
  cout << ((l + (n - 1) * (l + 5)) / d + 1) * d << '\n';
}
