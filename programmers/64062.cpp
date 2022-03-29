#include <string>
#include <vector>
#include <algorithm>
#define MAX 200000001

using namespace std;

bool can_pass(vector<int> stones, int n, int k)
{
  int cnt = 0;

  for (int i = 0; i < stones.size(); i++)
  {
    if (stones[i] - n > 0)
      cnt = 0;
    else
      cnt++;

    if (cnt == k)
      return false;
  }

  return true;
}

int solution(vector<int> stones, int k)
{
  int answer = MAX;
  int left = MAX;
  int right = 0;
  int mid = (left + right) / 2;

  for (int i = 0; i < stones.size(); i++)
  {
    left = min(left, stones[i]);
    right = max(right, stones[i]);
  }

  while (left <= right)
  {
    mid = (left + right) / 2;

    if (can_pass(stones, mid, k))
      left = mid + 1;
    else
    {
      right = mid - 1;
      answer = min(answer, mid);
    }
  }

  return answer;
}
