#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> lines)
{
  int s[24 * 3600 * 1000]{0};
  int e[24 * 3600 * 1000]{0};
  int cnt = 0, ans = 0;

  for (int i = 0; i < lines.size(); i++)
  {
    string t = lines[i].substr(11, 12);
    string d = lines[i].substr(24);

    int du = stod(d.substr(0, d.length() - 1)) * 1000;
    int en = (stod(t.substr(0, 2)) * 3600 + stod(t.substr(3, 2)) * 60 + stod(t.substr(6))) * 1000;
    int st = en - du + 1;

    if (st < 0)
      st = 0;
    s[st]++;
    e[en]++;
  }

  for (int i = 0; i < 1000; i++)
  {
    cnt += s[i];
  }
  ans = cnt;

  for (int i = 1000; i < 24 * 3600 * 1000; i++)
  {
    cnt += s[i];
    cnt -= e[i - 1000];
    ans = max(cnt, ans);
  }

  return ans;
}