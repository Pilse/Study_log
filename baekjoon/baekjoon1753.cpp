#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string.h>

using namespace std;

vector<pair<int, int> > vec[20001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int dist[20001];
int v, e;

void dijk(int s)
{
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty())
    {
        int distance = q.top().first;
        int p = q.top().second;
        q.pop();

        for (int i = 0; i < vec[p].size(); i++)
        {
            int w = vec[p][i].first;
            int d = vec[p][i].second;
            if (dist[w] <= distance + d)
                continue;
            dist[w] = distance + d;
            q.push({dist[w], w});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int start;

    cin >> v >> e;
    cin >> start;

    int t1, t2, t3;
    for (int i = 0; i < e; i++)
    {
        cin >> t1 >> t2 >> t3;
        vec[t1].push_back({t2, t3});
    }

    memset(dist, 555819297, sizeof(int) * (v + 1));
    dijk(start);

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == 555819297)
        {
            cout << "INF" << '\n';
            continue;
        }
        cout << dist[i] << '\n';
    }
}
