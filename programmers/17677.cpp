#include <string>
#include <map>
#include <cctype>

using namespace std;

bool is_valid(char c)
{
  if (c >= 'a' && c <= 'z')
    return true;
  else if (c >= 'A' && c <= 'Z')
    return true;
  else
    return false;
}

int solution(string str1, string str2)
{
  map<string, int> m1;
  map<string, int> m2;
  int de = 0, nu = 0;

  string st = "";
  for (int i = 0; i < str1.length(); i++)
  {
    char c = str1[i];
    if (is_valid(c))
    {
      st += tolower(c);
      if (st.length() == 2)
      {
        m1[st]++;
        de++;
        st = st[1];
      }
    }
    else
      st = "";
  }

  st = "";
  for (int i = 0; i < str2.length(); i++)
  {
    char c = str2[i];
    if (is_valid(c))
    {
      st += tolower(c);
      if (st.length() == 2)
      {
        m2[st]++;
        auto found = m1.find(st);
        if (found != m1.end())
        {
          int am = m2[st] - found->second;
          de += am > 0 ? 1 : 0;
          if (am <= 0)
            nu++;
        }
        else
          de++;

        st = st[1];
      }
    }
    else
      st = "";
  }

  if (de == 0)
    return 65536;
  return nu * 65536 / de;
}