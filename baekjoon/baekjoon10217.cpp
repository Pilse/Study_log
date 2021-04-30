#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 987654321

using namespace std;

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, greater<pair<pair<int, int>, int> > > pq;

int dp[201][10001];

int n, m, k;
int u, v, c, d;
int result = INF;

void fly(vector<pair<int, pair<int, int> > > vec[])
{
    pq.push({{0, 0}, 1});

    while (!pq.empty())
    {
        int distance = pq.top().first.first;
        int cost = pq.top().first.second;
        int cur = pq.top().second;
        pq.pop();
        //cout << distance << " " << cost << " " << cur << '\n';

        if (cur == n)
        {
            result = distance;
            return;
        }

        for (int i = 0; i < vec[cur].size(); i++)
        {
            int nw = vec[cur][i].first;
            int nc = vec[cur][i].second.first;
            int nd = vec[cur][i].second.second;

            if (cost + nc > m)
                continue;
            if (dp[nw][cost + nc] <= distance + nd)
                continue;

            dp[nw][cost + nc] = distance + nd;

            pq.push({{dp[nw][cost + nc], cost + nc}, nw});
        }
    }
    result = INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        vector<pair<int, pair<int, int> > > vec[101];

        cin >> n >> m >> k;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = INF;
            }
        }

        for (int i = 0; i < k; i++)
        {
            cin >> u >> v >> c >> d;
            vec[u].push_back({v, {c, d}});
        }

        fly(vec);

        if (result == INF)
            cout << "poor KCM" << '\n';
        else
            cout << result << '\n';
        result = INF;
    }
}