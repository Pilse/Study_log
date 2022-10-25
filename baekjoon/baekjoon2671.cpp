#include <iostream>
#include <regex>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;

  regex reg("(100+1+|01)+");

  cout << (regex_match(str, reg) ? "SUBMARINE" : "NOISE") << '\n';
}
