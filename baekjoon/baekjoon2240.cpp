#include <iostream>

using namespace std;

int t, n;
int arr[1001];
int dp[1001][31][2];

int plum(int time, int cnt, int pos, int sum)
{

  if (arr[time] == pos + 1)
    sum = 1;

  if (cnt > n)
    return -987654321;

  if (time == t && cnt <= n)
    return sum;

  if (dp[time][cnt][pos])
    return dp[time][cnt][pos];

  if (arr[time] == pos + 1)
    return dp[time][cnt][pos] = max(sum + plum(time + 1, cnt, pos, 0), sum + plum(time + 1, cnt + 1, (pos + 1) % 2, 0));
  else
    return dp[time][cnt][pos] = max(sum + plum(time + 1, cnt, pos, 0), sum + plum(time + 1, cnt + 1, (pos + 1) % 2, 0));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t >> n;

  for (int i = 1; i <= t; i++)
    cin >> arr[i];

  cout << plum(0, 0, 0, 0) << '\n';
}
