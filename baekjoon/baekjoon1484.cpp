#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> v;
  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      int big = n / i;
      int small = i;
      int sum = big + small;
      int diff = big - small;

      if (!diff)
        continue;
      if (sum % 2 != 0 || diff % 2 != 0)
        continue;

      v.push_back(sum / 2);
    }
  }

  if (v.size() == 0)
    cout << -1 << '\n';
  for (int i = v.size() - 1; i >= 0; i--)
    cout << v[i] << '\n';
}
