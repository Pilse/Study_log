#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n + 1, 0);
    for (int i = 1; i < nums.size(); i++)
    {
        int t;
        cin >> t;
        nums[i] = t;
    }

    int max_length = 1;
    vector<int> length(n + 1, 0);
    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];

        length[num] = length[num - 1] + 1;
        max_length = max(max_length, length[num]);
    }

    cout << n - max_length << '\n';
}
