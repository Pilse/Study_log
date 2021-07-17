#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  while (s != ".")
  {
    int m = s.length();
    int j = 0;
    vector<int> fail(m, 0);

    for (int i = 1; i < m; i++)
    {
      while (j > 0 && s[i] != s[j])
        j = fail[j - 1];
      if (s[i] == s[j])
        fail[i] = ++j;
    }
    if (fail[m - 1] == 0 || fail[m - 1] % (m - fail[m - 1]))
      cout << 1 << '\n';
    else
      cout << m / (m - fail[m - 1]) << '\n';
    cin >> s;
  }
}
