#include <iostream>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);

    long long *dist = new long long[n];
    long long *city = new long long[n];
    long long totalPrice = 0;
    dist[n - 1] = 0;

    for (long long i = 0; i < n - 1; i++)
        scanf("%lld", &dist[i]);
    for (long long i = 0; i < n; i++)
        scanf("%lld", &city[i]);

    long long idx = 0;
    while (idx < n - 1)
    {
        long long cnt = 0;
        long long totalDist = 0;

        for (long long i = idx + 1; i < n; i++)
        {
            if (min(city[idx], city[i]) == city[idx])
                cnt++;
            else
                break;
        }

        for (long long i = idx; i <= idx + cnt; i++)
            totalDist += dist[i];

        totalPrice += totalDist * city[idx];

        idx += cnt + 1;
    }
    printf("%lld\n", totalPrice);
}
