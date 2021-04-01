#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<pair<int, int> > v[10010];
queue<pair<int, int> > q;
int visited[10010];
int longest;
int endPoint;

void bfs(int idx)
{
    visited[idx] = 1;
    q.push(v[idx][0]);
    visited[v[idx][0].first] = 1;

    while (!q.empty())
    {
        int point = q.front().first;
        int len = q.front().second;

        q.pop();

        if (longest < len)
        {
            endPoint = point;
            longest = len;
        }

        for (int i = 0; i < v[point].size(); i++)
        {
            int w = v[point][i].first;

            if (!visited[w])
            {
                visited[w] = 1;
                q.push({w, v[point][i].second + len});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;
    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    int t1, t2, t3;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> t1 >> t2 >> t3;
        v[t1].push_back({t2, t3});
        v[t2].push_back({t1, t3});
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i].size() == 1)
        {
            bfs(i);
            break;
        }
    }
    memset(visited, 0, sizeof(int) * (n + 1));
    bfs(endPoint);

    cout << longest << '\n';
}
