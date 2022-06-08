#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
  int answer = 0;

  for (int i = 0; i < skill_trees.size(); i++)
  {
    string tree = skill_trees[i];
    int seq = 0;
    for (int j = 0; j < tree.length(); j++)
    {
      int idx = (int)skill.find(tree[j]);

      if (idx != -1 && seq != idx)
        break;
      if (idx != -1)
        seq++;

      if (j == tree.length() - 1)
        answer++;
    }
  }
  return answer;
}