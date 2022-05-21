#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
  int answer = 1e8;
  int w_size = weak.size();

  for (int i = 0; i < w_size - 1; i++)
  {
    weak.push_back(weak[i] + n);
  }

  sort(dist.begin(), dist.end());

  do
  {
    for (int i = 0; i < w_size; i++)
    {
      int cur = weak[i];
      int end = weak[i + w_size - 1];

      for (int j = 0; j < dist.size(); j++)
      {
        cur += dist[j];

        if (cur >= end)
        {
          answer = min(answer, j + 1);
          break;
        }

        for (int k = 0; k < weak.size(); k++)
        {
          if (cur < weak[k])
          {
            cur = weak[k];
            break;
          }
        }
      }
    }

  } while (next_permutation(dist.begin(), dist.end()));

  if (answer == 1e8)
    answer = -1;

  return answer;
}