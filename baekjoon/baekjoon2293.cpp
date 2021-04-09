#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

vector<int> v;
int dp[10001];
//int dp[101][10001];
//
//int coin(int round, int money)
//{
//    if(round == -1)
//        return 0;
//
//    if(dp[v[round]][money] != -1)
//        return dp[v[round]][money];
//
//    int iter = money / v[round];
//    dp[v[round]][money] = 0;
//
//    for(int i = iter; i >=0; i--)
//    {
//        if(money == v[round] * i)
//        {
//            dp[v[round]][money]++;
//            continue;
//        }
//        dp[v[round]][money] += coin(round - 1, money - v[round] * i);
//    }
//
//    return dp[v[round]][money];
//
//}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v.push_back(t);
    }

    //    sort(v.begin(), v.end(), less<int>());
    //    memset(dp, -1, sizeof(dp));
    //
    //    cout << coin(n - 1, k) << '\n';
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= k; j++)
            dp[j] += dp[j - v[i]];
    }

    cout << dp[k];
}
