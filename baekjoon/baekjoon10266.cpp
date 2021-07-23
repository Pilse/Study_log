#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string s)
{
  int n = s.size();
  int j = 0;
  vector<int> vec(n, 0);

  for (int i = 1; i < n; i++)
  {
    while (j > 0 && s[i] != s[j])
      j = vec[j - 1];
    if (s[i] == s[j])
      vec[i] = ++j;
  }
  return vec;
}

vector<int> kmp(string s, string t)
{
  int n = s.size();
  int m = t.size();
  int j = 0;
  vector<int> pi = getPi(t);
  vector<int> ans;

  for (int i = 0; i < n - 1; i++)
  {
    while (j > 0 && s[i] != t[j])
      j = pi[j - 1];
    if (s[i] == t[j])
    {
      if (j == m - 1)
      {
        ans.push_back(i - m + 1);
        j = pi[j];
      }
      else
        ++j;
    }
  }

  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  char c;

  cin >> n;

  string s, t;

  for (int i = 0; i < n; i++)
  {
    cin >> c;
    t += c;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> c;
    s += c;
  }

  int cnt = kmp(s + s, t).size();

  int a = n;
  int b = cnt;

  while (b != 0)
  {
    int r = a % b;
    a = b;
    b = r;
  }

  cout << cnt / a << '/' << n / a << '\n';
}
