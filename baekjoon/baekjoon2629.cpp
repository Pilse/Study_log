#include <iostream>

using namespace std;

int w[31];
int dp[31][40001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = 1;
                dp[i][j + w[i]] = 1;
                dp[i][abs(j - w[i])] = 1;
            }
            dp[i][w[i]] = 1;
        }
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m;
        cin >> m;

        if (dp[n][m])
            cout << "Y ";
        else
            cout << "N ";
    }
    cout << '\n';
}
