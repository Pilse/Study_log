#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    int *arr = new int[n];
    int x;
    int cnt = 0;
    int start = 0;
    int end = n - 1;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> x;
    sort(arr, arr + n, less<int>());

    if (n == 1)
        cout << "0" << '\n';
    else
    {
        while (start < end)
        {
            if (arr[start] + arr[end] < x)
                start++;

            else if (arr[start] + arr[end] > x)
                end--;
            else
            {
                cnt++;
                start++;
                end--;
            }
        }
    }
    cout << cnt << '\n';
}
