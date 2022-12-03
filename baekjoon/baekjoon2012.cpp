#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, tot = 0;

  cin >> n;

  vector<int> vec(n);

  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());

  for (int i = 1; i <= n; i++)
    tot += abs(vec[i - 1] - i);

  cout << tot << '\n';
}

// 2 3 5
// 1 2 3 4
// 3 2 1 6
// 2 1 3 4
// 2 3 1 4
