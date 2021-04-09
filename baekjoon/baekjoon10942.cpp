#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int arr[2001];
int dp[2001][2001];

bool palindrome(int s, int e)
{
    if (s > e)
        return 1;
    if (arr[s] != arr[e])
    {
        dp[s][e] = 0;
        return dp[s][e];
    }

    if (dp[s][e] != -1)
        return dp[s][e];

    dp[s][e] = palindrome(s + 1, e - 1);

    return dp[s][e];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> t;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < t; i++)
    {

        int s, e;
        cin >> s >> e;

        int flag = 1;

        if (!palindrome(s, e))
            flag = 0;

        if (!flag)
            cout << 0 << '\n';
        else
            cout << 1 << '\n';
    }
}
