#include <iostream>

using namespace std;

int get_switch_count(string src, string dest, int first);
void switch_num(string &str, int from);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string src, dest;

  cin >> n >> src >> dest;

  int cnt = min(get_switch_count(src, dest, 0), get_switch_count(src, dest, 1));

  if (cnt == 1e8)
    cout << -1 << '\n';
  else
    cout << cnt << '\n';
}

int get_switch_count(string src, string dest, int first)
{
  if (first)
    switch_num(src, 0);

  int cnt = first;

  for (int i = 1; i < src.length(); i++)
  {
    if (src[i - 1] != dest[i - 1])
    {
      switch_num(src, i);
      cnt++;
    }
  }

  return (src == dest) ? cnt : 1e8;
}

void switch_num(string &str, int from)
{
  for (int i = from - 1; i < from + 2; i++)
  {
    if (i < 0 || i >= str.length())
      continue;
    str[i] = str[i] == '1' ? '0' : '1';
  }
}
