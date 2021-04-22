#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int dp2[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int arr[100001] = {
        0,
    };

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp2[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    for (int i = n - 2; i >= 0; i--)
        dp2[i] = max(arr[i], dp2[i + 1] + arr[i]);

    int ans = *max_element(dp, dp + n);

    for (int i = 1; i < n - 1; i++)
        ans = max(ans, dp[i - 1] + dp2[i + 1]);

    cout << ans;
}
