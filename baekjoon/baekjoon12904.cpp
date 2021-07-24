#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  int left = 0;
  int right = t.length() - 1;
  int dir = 1;

  while (right - left != s.length() - 1)
  {
    if (dir)
    {
      if (t[right] == 'A')
        right--;
      else
      {
        right--;
        dir = 0;
      }
    }
    else
    {
      if (t[left] == 'A')
        left++;
      else
      {
        left++;
        dir = 1;
      }
    }
  }
  for (int i = 0; i < s.length(); i++)
  {
    if (dir)
    {
      if (s[i] != t[left++])
      {
        cout << 0 << '\n';
        return 0;
      }
    }
    else
    {
      if (s[i] != t[right--])
      {
        cout << 0 << '\n';
        return 0;
      }
    }
  }
  cout << 1 << '\n';
}
