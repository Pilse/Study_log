#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> vec;
int dp[10001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, t;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> t;
    vec.push_back(t);
  }

  for (int i = 1; i <= k; i++)
    dp[i] = 10001;

  for (int i = 1; i <= n; i++)
  {
    for (int j = vec[i - 1]; j <= k; j++)
    {
      dp[j] = min(dp[j], dp[j - vec[i - 1]] + 1);
      //            cout << dp[j] << " ";
    }
    //        cout << '\n';
  }

  if (dp[k] == 10001)
    cout << -1 << '\n';
  else
    cout << dp[k] << '\n';
}
