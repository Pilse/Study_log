#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for_each(nums.begin(), nums.end(), [](int &v)
             { cin >> v; });
    sort(nums.begin(), nums.end());

    int m;
    cin >> m;

    while (m--)
    {
        int t;
        cin >> t;

        auto result = lower_bound(nums.begin(), nums.end(), t);

        if (result == nums.end() || *result != t)
        {
            cout << 0 << '\n';
            continue;
        }

        cout << 1 << '\n';
    }
}
