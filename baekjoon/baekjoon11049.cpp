#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v;

int dp[501][501];

int matrix(int s, int e)
{
    if (s == e)
        return 0;

    if (s + 1 == e)
        return v[s].first * v[s].second * v[e].second;

    if (dp[s][e])
        return dp[s][e];

    dp[s][e] = INT_MAX;

    for (int i = s; i < e; i++)
        dp[s][e] = min(dp[s][e], matrix(s, i) + matrix(i + 1, e) + v[s].first * v[i + 1].first * v[e].second);

    return dp[s][e];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int t1, t2;
    ba

        for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;

        v.push_back({t1, t2});
    }

    int result = INT_MAX;

    for (int i = 0; i < n - 1; i++)
        result = min(result, matrix(0, i) + matrix(i + 1, n - 1) + v[0].first * v[i + 1].first * v[n - 1].second);

    cout << result;
}
