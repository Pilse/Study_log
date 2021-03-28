#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int least;

    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, less<int>());

    int start = 0;
    int end = n - 1;

    least = abs(arr[start] + arr[end]) + 1;
    pair<int, int> res;

    while (start < end)
    {
        int sum = arr[start] + arr[end];
        if (abs(arr[start] + arr[end]) < least)
        {
            least = abs(sum);
            res.first = start;
            res.second = end;
            if (sum == 0)
                break;
        }
        if (sum > 0)
            end--;
        else
            start++;
    }

    cout << arr[res.first] << " " << arr[res.second] << '\n';
}
