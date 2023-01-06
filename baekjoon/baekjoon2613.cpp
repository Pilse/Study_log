#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> marvels(n);
  vector<int> baskets[m];

  int l = 0, r = 0;
  for (auto &m : marvels)
  {
    cin >> m;
    l = max(l, m);
    r += m;
  }

  int answer = 999;
  int acnt = 0;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    int sum = 0;
    int cnt = 1;

    for (auto marvel : marvels)
    {
      sum += marvel;

      if (sum > mid)
      {
        cnt++;
        sum = marvel;
      }
    }

    if (cnt <= m)
    {
      if (mid < answer)
        answer = mid;
      acnt = cnt;
      r = mid - 1;
      continue;
    }

    l = mid + 1;
  }

  cout << answer << '\n';

  int sum = 0;
  int cnt = 0;
  int diff = m - acnt;

  for (auto marvel : marvels)
  {
    sum += marvel;
    cnt++;

    if (sum > answer)
    {
      if (cnt - 1 > 1 && diff)
      {
        while (cnt - 1 > 1 && diff)
        {
          cout << 1 << " ";
          cnt--;
          diff--;
        }
        cout << cnt - 1 << " ";

        sum = marvel;
        cnt = 1;

        continue;
      }

      cout << cnt - 1 << " ";
      sum = marvel;
      cnt = 1;
    }
  }
  cout << cnt << '\n';
}
