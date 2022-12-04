#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  sort(vec.begin(), vec.end());

  int idx = 0;

  idx = vec.size() % 2 == 0 ? (int)vec.size() / 2 - 1 : (int)vec.size() / 2;

  cout << vec[idx] << '\n';
}
