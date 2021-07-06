#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string str)
{
  int len = (int)str.length();
  int mid;
  bool is_pass = false;
  bool second_chance = true;

  if (len % 2 == 0)
    mid = len / 2;
  else
    mid = (len - 1) / 2;

  for (int i = 0; i < mid; i++)
  {
    if (str[i] != str[len - i - 1])
    {
      if (str[i + 1] == str[len - i - 1])
      {
        second_chance = false;
        if (len % 2 == 0)
          mid -= 1;
        for (int j = i; j < mid; j++)
        {
          if (str[j + 1] != str[len - j - 1])
            break;
          if (j == mid - 1)
            is_pass = true;
        }
        if (is_pass)
          break;
      }
      if (str[i] == str[len - i - 2])
      {
        second_chance = false;
        if (len % 2 == 0)
          mid -= 1;
        for (int j = i; j < mid; j++)
        {
          if (str[j] != str[len - j - 2])
            return 2;
        }
        break;
      }
      return 2;
    }
  }
  if (second_chance)
    return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string str;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> str;
    cout << isPalindrome(str) << '\n';
  }
}
