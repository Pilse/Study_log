#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int l;
  string s;

  cin >> l;
  cin >> s;

  int m = s.length();
  int j = 0;
  vector<int> pi(m, 0);

  for (int i = 1; i < m; i++)
  {
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      pi[i] = ++j;
  }
  cout << l - pi[m - 1] << '\n';
}
