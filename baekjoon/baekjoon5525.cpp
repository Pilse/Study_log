#include <iostream>
#include <vector>
#include <string>

using namespace std;

string get_target(int n)
{
  string return_target = "IOI";

  for (int i = 1; i < n; i++)
    return_target += "OI";

  return return_target;
}

vector<int> get_pi(string s)
{
  int m = (int)s.length();
  int j = 0;
  vector<int> pi(m, 0);

  for (int i = 1; i < m; i++)
  {
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];

    if (s[i] == s[j])
      pi[i] = ++j;
  }

  return pi;
}

vector<int> kmp(string s, string t)
{
  auto pi = get_pi(t);

  vector<int> res;

  int n = (int)s.length();
  int m = (int)t.length();
  int j = 0;

  for (int i = 0; i < n; i++)
  {
    while (j > 0 && s[i] != t[j])
      j = pi[j - 1];

    if (s[i] == t[j])
    {
      if (j == m - 1)
      {
        res.push_back(j);
        j = pi[j];
      }
      else
        j++;
    }
  }

  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  string str;

  cin >> n >> m >> str;

  string target = get_target(n);

  cout << kmp(str, target).size() << '\n';
}
