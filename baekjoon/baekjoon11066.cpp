#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>

using namespace std;

int dp[501][501];

vector<int> v;
vector<int> sum;

int compose(int s, int e)
{
    if (s == e)
        return v[s];

    int rsum = sum[e] - sum[s - 1];

    if (dp[s][e])
        return dp[s][e];
    else
    {
        dp[s][e] = INT_MAX;
        for (int i = s; i < e; i++)
            dp[s][e] = min(dp[s][e], compose(s, i) + compose(i + 1, e) + rsum);
        return dp[s][e];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;
        int result = INT_MAX;

        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            if (i == 0)
                sum.push_back(temp);

            v.push_back(temp);
            if (i > 0)
                sum.push_back(sum[i - 1] + v[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            result = min(result, compose(0, i) + compose(i + 1, n - 1));
        }

        cout << result << '\n';

        vector<int>().swap(v);
        vector<int>().swap(sum);
        memset(dp, 0, sizeof(dp));
    }
}
