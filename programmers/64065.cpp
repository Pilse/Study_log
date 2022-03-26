#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_opening_tag(char c)
{
  return c == '{';
}

bool is_closing_tag(char c)
{
  return c == '}';
}

bool is_comma(char c)
{
  return c == ',';
}

bool is_num(char c)
{
  return (!is_opening_tag(c) && !is_closing_tag(c) && !is_comma(c));
}

vector<pair<int, vector<int> > > filter_tuple(string s)
{
  vector<pair<int, vector<int> > > tuple;
  string str = "";
  vector<int> temp;

  for (int i = 0; i < s.length(); i++)
  {
    if (is_opening_tag(s[i]) || is_comma(s[i]))
      continue;

    if (is_closing_tag(s[i]))
    {
      if (temp.size() > 0)
      {
        tuple.push_back({temp.size(), temp});
        vector<int>().swap(temp);
      }

      continue;
    }

    str += s[i];

    if (is_num(s[i + 1]))
      continue;

    int number = stoi(str);
    str = "";

    temp.push_back(number);
  }

  return tuple;
}

vector<int> filter_answer(vector<pair<int, vector<int> > > tuple)
{
  vector<int> answer;

  for (int i = 0; i < tuple.size(); i++)
  {
    for (int j = 0; j < tuple[i].second.size(); j++)
    {
      bool new_ele_flag = true;
      int number = tuple[i].second[j];

      for (int k = 0; k < answer.size(); k++)
      {
        if (answer[k] == number)
        {
          new_ele_flag = false;
          break;
        }
      }

      if (new_ele_flag)
        answer.push_back(number);
    }
  }

  return answer;
}

vector<int> solution(string s)
{
  vector<pair<int, vector<int> > > tuple = filter_tuple(s);

  sort(tuple.begin(), tuple.end());

  vector<int> answer = filter_answer(tuple);

  return answer;
}