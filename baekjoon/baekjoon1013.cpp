#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  regex re("(100+1+|01)+");

  int t;
  cin >> t;

  while (t--)
  {
    string str;
    cin >> str;

    string answer = regex_match(str, re) ? "YES" : "NO";

    cout << answer << '\n';
  }
}
