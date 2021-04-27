#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <climits>
#define MAX 8000000

using namespace std;

vector<pair<int, int> > v[801];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int n, e;
int v1, v2;
int arr[802];
int e1[802];
int e2[802];

void dijk(int s, int a[])
{
    a[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int d = v[cur][i].first;
            int w = v[cur][i].second;

            if (a[w] <= dist + d)
                continue;
            a[w] = dist + d;
            pq.push({a[w], w});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;

    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    cin >> v1 >> v2;

    fill_n(arr, n + 1, MAX);
    fill_n(e1, n + 1, MAX);
    fill_n(e2, n + 1, MAX);

    dijk(1, arr);
    dijk(v1, e1);
    dijk(v2, e2);

    int toV1 = arr[v1];
    int toV2 = arr[v2];
    int v1ToV2 = e1[v2];
    int result;

    if (toV1 == MAX || toV2 == MAX || v1ToV2 == MAX)
        result = MAX;
    else
        result = min(toV1 + v1ToV2 + e2[n], toV2 + v1ToV2 + e1[n]);

    if (result == MAX)
        cout << -1;
    else
        cout << result << '\n';
}
