#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  vector<int> vec;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;

    if (vec.empty() || vec.back() < t)
    {
      vec.push_back(t);
      continue;
    }

    *lower_bound(vec.begin(), vec.end(), t) = t;
  }

  cout << vec.size() << '\n';
}
