#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
  for (int i = 1; i < triangle.size(); i++)
  {
    triangle[i][0] += triangle[i - 1][0];
    for (int j = 1; j < triangle[i].size() - 1; j++)
    {
      triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
    }
    triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i].size() - 2];
  }

  int answer = 0;
  for (int j = 0; j < triangle[triangle.size() - 1].size(); j++)
  {
    answer = max(answer, triangle[triangle.size() - 1][j]);
  }

  return answer;
}