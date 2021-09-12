#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dp[101][101];

string bigIntAdd(string num1, string num2)
{
  long long sum = 0;
  string result;

  while (!num1.empty() || !num2.empty() || sum)
  {
    if (!num1.empty())
    {
      sum += num1.back() - '0';
      num1.pop_back();
    }
    if (!num2.empty())
    {
      sum += num2.back() - '0';
      num2.pop_back();
    }
    result.push_back((sum % 10) + '0');
    sum /= 10;
  }
  reverse(result.begin(), result.end());
  return result;
}

string combination(int n, int m)
{
  if (n == m || m == 0)
    return "1";
  if (dp[n][m] != "")
    return dp[n][m];

  return dp[n][m] = bigIntAdd(combination(n - 1, m), combination(n - 1, m - 1));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  cout << combination(n, m) << '\n';
}
