#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool check_candidate(vector<vector<string> > relation, vector<int> ci)
{
  map<string, int> m;

  for (int i = 0; i < relation.size(); i++)
  {
    vector<string> row = relation[i];

    string key = "";

    for (int j = 0; j < ci.size(); j++)
      key += row[ci[j]];

    auto res = m.find(key);

    if (res != m.end())
    {
      return false;
    }

    m[key] = 0;
  }

  return true;
}

void combination(vector<vector<int> > &comb, vector<int> &temp, int n_c, int len, int next, int step)
{
  if (step == len)
  {
    if (temp.size() < len)
      return;

    comb.push_back(temp);
    return;
  }

  for (int i = next; i < n_c; i++)
  {
    temp.push_back(i);
    combination(comb, temp, n_c, len, i + 1, step + 1);
    temp.pop_back();
  }
}

vector<vector<int> > get_combination(int len, int n_c)
{
  vector<vector<int> > comb;
  vector<int> temp;

  combination(comb, temp, n_c, len, 0, 0);

  return comb;
}

bool is_minimality(vector<string> keys, vector<int> c)
{
  string key = "";

  for (int i = 0; i < c.size(); i++)
    key += (char)(c[i] + 48);

  for (int i = 0; i < keys.size(); i++)
  {
    bool minimality = false;
    for (int j = 0; j < keys[i].size(); j++)
    {
      if (key.find(keys[i][j]) == std::string::npos)
      {
        minimality = true;
        break;
      }
    }
    if (!minimality)
      return false;
  }

  return true;
}

int solution(vector<vector<string> > relation)
{
  int answer = 0;
  int n_c = relation[0].size();
  vector<string> keys;

  for (int i = 1; i <= n_c; i++)
  {
    vector<vector<int> > comb = get_combination(i, n_c);

    for (int j = 0; j < comb.size(); j++)
    {
      if (!is_minimality(keys, comb[j]))
        continue;

      if (check_candidate(relation, comb[j]))
      {
        answer++;

        string key = "";
        for (int k = 0; k < comb[j].size(); k++)
          key += (char)(comb[j][k] + 48);
        keys.push_back(key);
      }
    }
  }

  return answer;
}