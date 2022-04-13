#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
  vector<int> answer;
  map<string, int> m;
  int ni = 1, idx = 0;

  for (; ni <= 26; ni++)
  {
    string str = "";
    str = char('A' + ni - 1);
    m[str] = ni;
  }

  while (idx < msg.length())
  {
    string w = "", c = "";

    w = msg[idx++];
    while (idx < msg.length() &&
           m.find(w + msg[idx]) != m.end())
      w += msg[idx++];

    answer.push_back(m[w]);

    c = msg[idx];

    m[w + c] = ni++;
  }

  return answer;
}
