#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<long long> v1(n);
  vector<long long> v2(n);
  vector<long long> v3(n);
  vector<long long> v4(n);

  for (int i = 0; i < n; i++)
  {
    cin >> v1[i] >> v2[i] >> v3[i] >> v4[i];
  }

  vector<long long> sum1(n * n);
  vector<long long> sum2(n * n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum1[i * n + j] = v1[i] + v2[j];
      sum2[i * n + j] = v3[i] + v4[j];
    }
  }

  sort(sum2.begin(), sum2.end());

  long long cnt = 0;

  for (auto &v : sum1)
  {
    if (sum2[lower_bound(sum2.begin(), sum2.end(), -v) - sum2.begin()] == -v)
    {
      long long pre = lower_bound(sum2.begin(), sum2.end(), -v) - sum2.begin();
      long long post = upper_bound(sum2.begin(), sum2.end(), -v) - sum2.begin();

      cnt += post - pre;
    }
  }

  cout << cnt << '\n';
}
