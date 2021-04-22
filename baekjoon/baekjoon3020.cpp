#include <iostream>
#include <algorithm>

using namespace std;
int top[500010];
int bot[500010];
int sum[500010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, c;
    cin >> n >> h;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (i % 2 == 0)
            bot[c]++;
        else
            top[c]++;
    }

    for (int i = h - 2; i >= 1; i--)
    {
        bot[i] += bot[i + 1];
        top[i] += top[i + 1];
    }
    for (int i = 1; i <= h; i++)
    {
        sum[i] = bot[i] + top[h - i + 1];
    }

    sort(sum + 1, sum + h + 1, less<int>());

    cout << sum[1] << " " << upper_bound(sum + 1, sum + h + 1, sum[1]) - lower_bound(sum + 1, sum + h + 1, sum[1]);
}
