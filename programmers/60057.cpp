#include <iostream>
#include <string>
#include <vector>

using namespace std;

int zipped_str_len(string str, int z)
{
  int cnt = 1;
  string base = "", target = "", zipped = "";

  for (int i = 0; i < z; i++)
    base += str[i];

  for (int i = z; i < str.length(); i++)
  {
    target += str[i];
    if (target.length() == z)
    {
      if (base != target)
      {
        if (cnt > 1)
          zipped += to_string(cnt);
        zipped += base;
        cnt = 1;
        base = target;
      }
      else
        cnt++;
      target = "";
    }
  }
  if (cnt > 1)
    zipped += to_string(cnt);
  zipped += base + target;

  return zipped.length();
}

int solution(string s)
{
  int answer = s.length();
  for (int i = 1; i <= s.length() / 2 + 1; i++)
    answer = min(answer, zipped_str_len(s, i));
  return answer;
}