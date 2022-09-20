#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
  vector<int> p(5);
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 1;
  p[4] = 1;
  problems.push_back(p);
  p[2] = 1;
  p[3] = 0;
  problems.push_back(p);

  int max_alp = alp, max_cop = cop;
  for (vector<int> p : problems)
  {
    max_alp = max(max_alp, p[0]);
    max_cop = max(max_cop, p[1]);
  }

  vector<vector<int>> dp(max_alp + 1, vector<int>(max_cop + 1, 1e8));
  dp[alp][cop] = 0;

  for (int a = alp; a < dp.size(); a++)
  {
    for (int c = cop; c < dp[0].size(); c++)
    {
      for (vector<int> p : problems)
      {
        if (a < p[0] || c < p[1])
          continue;

        int al = min(max_alp, a + p[2]);
        int co = min(max_cop, c + p[3]);

        dp[al][co] = min(dp[al][co], dp[a][c] + p[4]);
      }
    }
  }

  return dp[max_alp][max_cop];
}
