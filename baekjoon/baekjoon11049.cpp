#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;
vector<int> sum;
int dp[501][501];

int matrix(int s, int e)
{
    cout << s << " " << e << '\n';
    if (s == e)
        return 0;
    if (dp[s][e])
        return dp[s][e];

    int psum = sum[e] - sum[s - 1];
    dp[s][e] = INT_MAX;

    for (int i = s; i < e; i++)
        dp[s][e] = min(dp[s][e], matrix(s, i) + matrix(i + 1, e) + psum);

    return dp[s][e];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int t1, t2;

    sum.push_back(0);

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;

        v.push_back({t1, t2});

        if (i > 0)
            sum.push_back(sum[i - 1] + v[0].first * t1 * t2);
    }

    int result = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        result = min(result, matrix(0, i) + matrix(i + 1, n - 1));
    }

    cout << result;
}
