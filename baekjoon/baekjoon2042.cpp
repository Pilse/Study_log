#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> tree;
vector<long long> sums;

long long init(int cur, int start, int end)
{
  cout << cur << start << end << '\n';
  if (start == end)
    return tree[cur] = sums[start];
  int mid = (start + end) / 2;
  return tree[cur] = init(cur * 2, start, mid) + init(cur * 2 + 1, mid + 1, end);
}

void update(int cur, int at, int start, int end, long long value)
{
  if (at < start || at > end)
    return;
  tree[cur] += value;
  if (start == end)
    return;
  int mid = (start + end) / 2;
  update(cur * 2, at, start, mid, value);
  update(cur * 2 + 1, at, mid + 1, end, value);
}

long long sum(int cur, int start, int end, int left, int right)
{
  if (left > end || right < start)
    return 0;
  if (left <= start && right >= end)
    return tree[cur];
  int mid = (start + end) / 2;
  return sum(cur * 2, start, mid, left, right) + sum(cur * 2 + 1, mid + 1, end, left, right);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  tree.resize(1 << (int)(ceil(log2(n)) + 1));
  sums.resize(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> sums[i];

  init(1, 1, n);

  for (int i = 0; i < m + k; i++)
  {
    int a, b;
    long long c;
    cin >> a >> b >> c;

    if (a == 1)
    {
      update(1, b, 1, n, c - sums[b]);
      sums[b] = c;
      continue;
    }

    cout << sum(1, 1, n, b, (int)c) << '\n';
  }
}
