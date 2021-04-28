#include <iostream>
#include <queue>
#include <vector>
#define MAX 2000001

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
priority_queue<int, vector<int>, greater<int> > r;
int dest[101];
int arr[2001];
int g1[2001];
int h1[2001];

void dijk(int s, int a[], vector<pair<int, int> > v[])
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
            if (a[w] < dist + d)
                continue;
            a[w] = dist + d;
            pq.push({a[w], w});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int n, m, t;
        int s, g, h;
        vector<pair<int, int> > v[2001];
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int j = 0; j < m; j++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({c, b});
            v[b].push_back({c, a});
        }
        for (int j = 0; j < t; j++)
        {
            cin >> dest[j];
        }

        for (int i = 1; i <= n; i++)
        {
            arr[i] = MAX;
            g1[i] = MAX;
            h1[i] = MAX;
        }

        dijk(s, arr, v);
        dijk(g, g1, v);
        dijk(h, h1, v);

        int sToG = arr[g];
        int sToH = arr[h];
        int GbetH = g1[h];

        for (int j = 0; j < t; j++)
        {
            int c = dest[j];
            int distance;

            if (sToG == MAX || sToH == MAX || GbetH == MAX)
                distance = MAX;
            else
                distance = min(sToG + GbetH + h1[c], sToH + GbetH + g1[c]);

            if (distance == arr[c])
                r.push(c);
        }
        while (!r.empty())
        {
            cout << r.top() << " ";
            r.pop();
        }

        cout << '\n';
    }
}
