#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_unique_count(vector<string> vec);
vector<string> get_sub_strings(string str);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;

  cin >> str;

  vector<string> sub_strings = get_sub_strings(str);

  cout << get_unique_count(sub_strings) << '\n';
}

int get_unique_count(vector<string> vec)
{
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  return (int)vec.size();
}

vector<string> get_sub_strings(string str)
{
  int len = (int)str.length();
  vector<string> sub_strings;

  for (int t = 0; t < len; t++)
  {
    for (int i = 1; i <= len - t; i++)
    {
      sub_strings.push_back(str.substr(t, i));
    }
  }

  return sub_strings;
}
