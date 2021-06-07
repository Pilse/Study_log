#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
struct gem
{
    long long m, v;
};
bool operator<(gem g1, gem g2)
{
    if (g1.v == g2.v)
        return (g1.m < g2.m);
    return (g1.v < g2.v);
}
bool comp(gem g1, gem g2)
{
    return (g1.m < g2.m);
}

gem g[300005];
int c[300005];
priority_queue<gem> pq;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> g[i].m >> g[i].v;
    sort(g, g + n, comp);

    for (int i = 0; i < k; i++)
        cin >> c[i];
    sort(c, c + k);

    long long int total = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (g[idx].m <= c[i])
        {
            pq.push(g[idx]);
            idx++;
            if (idx == k)
                break;
        }
        if (!pq.empty())
        {
            total = total + ((double)pq.top().v);
            pq.pop();
        }
    }
    cout << total;
}
