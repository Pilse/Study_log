#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int *arr;
int *idx;
int idx1[2][4010];

int main()
{
    int n;
    double sum = 0;
    int cnt = 0;
    int index = 0;

    scanf("%d", &n);

    arr = new int[n + 1];

    int freq = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] < 0)
        {
            idx1[0][abs(arr[i])]++;
            freq = max(freq, idx1[0][abs(arr[i])]);
        }
        else
        {
            idx1[1][arr[i]]++;
            freq = max(freq, idx1[1][arr[i]]);
        }
    }

    sort(arr, arr + n, less<int>());

    for (int i = 0; i < n; i++)
        sum += (double)arr[i];

    printf("%0.lf\n", floor(sum / n + 0.5));
    printf("%d\n", arr[(n - 1) / 2]);

    int result = 0;

    while (cnt < 2 && index < n)
    {
        if (upper_bound(arr, arr + n, arr[index], less<int>()) - lower_bound(arr, arr + n, arr[index], less<int>()) == freq)
        {
            cnt++;
            result = index;
            index += freq;
        }
        else
            index++;
    }
    printf("%d\n", arr[result]);
    printf("%d\n", arr[n - 1] - arr[0]);
}
