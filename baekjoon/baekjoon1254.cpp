#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s)
{
  int l = (int)s.length();

  for (int i = 0; i < l / 2; i++)
  {
    if (s[i] != s[l - i - 1])
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;

  cin >> str;

  int l = (int)str.length();

  for (int i = 0; i < l; i++)
  {
    if (is_palindrome(str.substr(i, l)))
    {
      cout << l + i << '\n';
      return 0;
    }
  }

  cout << l * 2 << '\n';
}
