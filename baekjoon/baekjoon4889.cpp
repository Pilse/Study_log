#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  int idx = 0;

  cin >> str;

  while (str[0] != '-')
  {
    idx++;
    int open = 0;
    int close = 0;
    int cnt = 0;

    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == '{')
        open++;
      if (str[i] == '}')
      {
        if (open)
          open--;
        else
          close++;
      }
    }

    cnt = close / 2 + open / 2;
    cnt += close % 2 + close % 2;

    cout << idx << ". " << cnt << '\n';

    cin >> str;
  }
}
