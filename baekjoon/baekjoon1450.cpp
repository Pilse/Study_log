#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combination_sum(int start, int end, long long sum, vector<int> &target, vector<long long> &container);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, c;
  cin >> n >> c;

  vector<int> things(n);
  for_each(things.begin(), things.end(), [](int &v)
           { cin >> v; });

  vector<long long> lsum, rsum;

  combination_sum(0, n / 2 - 1, 0, things, lsum);
  combination_sum(n / 2, n - 1, 0, things, rsum);

  sort(rsum.begin(), rsum.end());

  int tot = 0;
  for (long long sum : lsum)
    tot += upper_bound(rsum.begin(), rsum.end(), c - sum) - rsum.begin();

  cout << tot << '\n';
}

void combination_sum(int start, int end, long long sum, vector<int> &target, vector<long long> &container)
{
  if (start > end)
  {
    container.push_back(sum);
    return;
  }

  combination_sum(start + 1, end, sum, target, container);
  combination_sum(start + 1, end, sum + target[start], target, container);
}
