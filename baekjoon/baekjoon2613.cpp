#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, l = 0, r = 0;
  cin >> n >> m;

  vector<int> marvels(n);
  vector<int> baskets(m);

  for (auto &m : marvels)
  {
    cin >> m;
    l = max(l, m);
    r += m;
  }

  int ans_sum = 0;
  int ans_cnt = 0;

  while (l <= r)
  {
    int mid = (l + r) / 2;
    int sum = 0;
    int cnt = 1;

    for (auto marvel : marvels)
    {
      if (sum + marvel <= mid)
      {
        sum += marvel;
        continue;
      }

      sum = marvel;
      cnt++;
    }

    if (cnt <= m)
    {
      ans_sum = mid;
      ans_cnt = cnt;
      r = mid - 1;
      continue;
    }

    l = mid + 1;
  }

  cout << ans_sum << '\n';

  int sum = 0;
  int cnt = 0;
  int diff = m - ans_cnt;
  for (auto marvel : marvels)
  {
    if (sum + marvel <= ans_sum)
    {
      sum += marvel;
      cnt++;
      continue;
    }

    while (cnt > 1 && diff)
    {
      cout << 1 << " ";
      cnt--;
      diff--;
    }

    if (cnt == 0)
      cout << 1 << " ";
    else
      cout << cnt << " ";
    cnt = 1;
    sum = marvel;
  }

  while (cnt > 1 && diff)
  {
    cout << 1 << " ";
    cnt--;
    diff--;
  }

  cout << cnt << " ";
}
