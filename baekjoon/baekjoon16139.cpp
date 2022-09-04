#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;

  vector<vector<int>> dp(str.length() + 1, vector<int>(26, 0));

  for (int i = 1; i < dp.size(); i++)
  {
    for (int j = 0; j < dp[0].size(); j++)
      dp[i][j] = dp[i - 1][j];

    dp[i][str[i - 1] - 'a']++;
  }

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    char c;
    int s, e;

    cin >> c >> s >> e;

    cout << dp[e + 1][c - 'a'] - dp[s][c - 'a'] << '\n';
  }
}
