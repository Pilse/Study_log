#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k, answer = 0;
  vector<string> v;

  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    v.push_back(str);
  }

  cin >> k;

  for (auto &lamp : v)
  {
    int cnt = 0;
    for (auto &bulb : lamp)
      if (bulb == '0')
        cnt++;

    if (!(cnt <= k && cnt % 2 == k % 2))
      continue;

    cnt = 0;
    for (auto &alamp : v)
      if (lamp == alamp)
        cnt++;

    answer = max(answer, cnt);
  }

  cout << answer << '\n';
}
