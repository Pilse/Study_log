#include <iostream>
#include <string>
#include <vector>
// balanced
// correct
using namespace std;

pair<string, string> balanced_split(string str)
{
  int open = 0, close = 0;
  string u = "", v = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(')
      open++;
    else
      close++;
    if (open && close && open == close)
    {
      u = str.substr(0, i + 1);
      v = str.substr(i + 1);
      break;
    }
  }
  return {u, v};
}

bool is_accurate(string str)
{
  int cnt = 0;
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(')
      cnt++;
    else
      cnt--;
    if (cnt < 0)
      return false;
  }
  return true;
}

string reverse(string str)
{
  string reversed = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '(')
      reversed += ')';
    else
      reversed += '(';
  }
  return reversed;
}

string transform(string str)
{
  if (!str.length())
    return "";

  pair<string, string> splited = balanced_split(str);
  string u = splited.first;
  string v = splited.second;

  if (is_accurate(u))
  {
    return u + transform(v);
  }
  else
  {
    string s = "(";
    s += transform(v);
    s += ')';
    s += reverse(u.substr(1, u.length() - 2));
    return s;
  }
}

string solution(string p)
{
  return transform(p);
}