#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
vector<vector<int>> dp;

bool isPalindrome(int s, int e)
{
    if (dp[s][e] != -1)
        return dp[s][e];

    if (e - s > 1)
        return dp[s][e] = nums[s] != nums[e] ? 0 : isPalindrome(s + 1, e - 1);

    return dp[s][e] = nums[s] == nums[e];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n;
    nums.resize(n);

    for_each(nums.begin(), nums.end(), [](int &v)
             { cin >> v; });

    cin >> m;
    dp.resize(n, vector<int>(n, -1));

    while (m--)
    {
        int s, e;
        cin >> s >> e;

        cout << isPalindrome(s - 1, e - 1) << '\n';
    }
}
