#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int min_distance(int start, int end, vector<vector<pair<int, int>>> &vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> vec(n + 1);

    while (e--)
    {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;

        vec[v1].push_back({v2, c});
        vec[v2].push_back({v1, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int dist1 = min_distance(1, v1, vec);
    int dist2 = min_distance(1, v2, vec);
    int dist3 = min_distance(v1, v2, vec);
    int dist4 = min_distance(v1, n, vec);
    int dist5 = min_distance(v2, n, vec);

    if ((dist1 == 1e8 && dist2 == 1e8) || dist3 == 1e8 || (dist4 == 1e8 && dist5 == 1e8))
    {
        cout << -1 << '\n';
        return 0;
    }

    cout << min(dist1 + dist3 + dist5, dist2 + dist3 + dist4) << '\n';
}

int min_distance(int start, int end, vector<vector<pair<int, int>>> &vec)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(vec.size(), 1e8);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_cost = pq.top().first;
        int cur_pos = pq.top().second;

        pq.pop();

        for (int i = 0; i < vec[cur_pos].size(); i++)
        {
            int next_pos = vec[cur_pos][i].first;
            int next_cost = vec[cur_pos][i].second;

            if (dist[next_pos] > cur_cost + next_cost)
            {
                dist[next_pos] = cur_cost + next_cost;
                pq.push({dist[next_pos], next_pos});
            }
        }
    }

    return dist[end];
}
