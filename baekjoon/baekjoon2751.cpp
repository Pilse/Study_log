#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int *arr;
    scanf("%d", &n);
    arr = new int[n];

    sort(arr, arr + n, less<int>());

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}