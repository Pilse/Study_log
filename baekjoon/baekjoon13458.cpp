#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, b, c;
  cin >> n;
  long long cnt = n;

  vector<int> rooms(n);
  for_each(rooms.begin(), rooms.end(), [](int &v)
           { cin >> v; });

  cin >> b >> c;
  for (auto &r : rooms)
  {
    r -= b;
    if (r <= 0)
      continue;
    cnt += (r / c);
    cnt += (r % c) ? 1 : 0;
  }

  cout << cnt << '\n';
}
