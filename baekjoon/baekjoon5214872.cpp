#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &n : nums)
        cin >> n;

    sort(nums.begin(), nums.end());

    unordered_set<int> s;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == 0 && !(j + 1 < n && nums[j] == nums[j + 1]))
                continue;
            if (nums[j] == 0 && !(i - 1 >= 0 && nums[i - 1] == nums[i]))
                continue;

            s.insert(nums[i] + nums[j]);
        }

    int cnt = 0;
    for (auto n : nums)
        if (s.find(n) != s.end())
            cnt++;

    cout << cnt << '\n';
}
