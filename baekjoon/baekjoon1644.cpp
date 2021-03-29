#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    vector<int> acc;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    v.push_back(2);
    v.push_back(3);
    acc.push_back(2);
    acc.push_back(5);

    for (int i = 5; i <= n; i++)
    {
        int flag = 0;

        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            v.push_back(i);
            acc.push_back(acc[acc.size() - 1] + i);
        }
    }
    int start = 0;
    int end = 0;
    int cnt = 0;
    int vSize = v.size();

    while (start < vSize && end < vSize && start <= end)
    {
        int sum = 0;
        if (start == 0)
            sum = acc[end];
        else
            sum = acc[end] - acc[start - 1];
        if (sum == n)
        {
            cnt++;
            start++;
        }
        else if (sum > n)
            start++;
        else
            end++;
    }

    cout << cnt << '\n';
}
