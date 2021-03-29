#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;

    cin >> n >> s;

    int *arr = new int[n];
    int *acc = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i == 0)
            acc[i] = arr[i];
        else
            acc[i] = acc[i - 1] + arr[i];
    }

    int start = 0;
    int end = 0;
    int len = 1000000000;

    while (start < n && end < n && start <= end)
    {
        int sum = 0;

        if (start == 0)
            sum = acc[end];
        else
            sum = acc[end] - acc[start - 1];

        if (sum >= s)
        {
            len = min(len, end - start + 1);

            if (len == 1)
                break;

            start++;
        }
        else
            end++;
    }
    if (len == 1000000000)
        cout << "0";
    else
        cout << len << '\n';
}
