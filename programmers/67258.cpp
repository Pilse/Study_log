#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems)
{
  vector<int> answer(2);
  set<string> num(gems.begin(), gems.end());
  unordered_map<string, int> m;
  int left = 0, right = 0, minimum;

  for (int i = 0; i < gems.size(); i++)
  {
    m[gems[i]]++;

    if (m.size() == num.size())
      break;
    right++;
  }

  minimum = right - left;
  answer[0] = left + 1;
  answer[1] = right + 1;

  while (left <= right)
  {
    string gem = gems[left];
    m[gem]--;
    left++;

    if (m[gem] == 0)
    {
      right++;

      for (; right < gems.size(); right++)
      {
        m[gems[right]]++;

        if (gems[right] == gem)
          break;
      }

      if (right == gems.size())
        break;
    }

    if (minimum > right - left)
    {
      minimum = right - left;

      answer[0] = left + 1;
      answer[1] = right + 1;
    }
  }

  return answer;
}