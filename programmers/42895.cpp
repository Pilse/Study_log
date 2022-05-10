#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int N, int number)
{
  vector<set<int>> v(10);

  int d = 0;
  for (int i = 1; i <= 9; i++)
  {
    d += pow(10, i - 1) * N;
    v[i].insert(d);
  }

  for (int i = 2; i <= 9; i++)
  {
    for (int s = 1; s < i; s++)
    {
      for (auto j = v[s].begin(); j != v[s].end(); j++)
      {
        for (auto k = v[i - s].begin(); k != v[i - s].end(); k++)
        {
          v[i].insert(*j + *k);
          v[i].insert(*j - *k);
          v[i].insert(*j * *k);
          if (*k)
            v[i].insert(*j / *k);
        }
      }
    }
  }

  for (int i = 1; i <= 9; i++)
  {
    if (v[i].find(number) != v[i].end())
      return i;
  }

  return -1;
}