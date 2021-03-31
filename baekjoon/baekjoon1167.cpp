#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<pair<int, int> > v[100001];
queue<pair<int, int> > q;
int visited[100001];
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
        if (longest < len)
        {
            endPoint = point;
            longest = len;
        }

        q.pop();

        for (int i = 0; i < v[point].size(); i++)
        {
            int w = v[point][i].first;
            if (!visited[w])
            {
                visited[w] = 1;
                q.push({w, len + v[point][i].second});
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
    int p;

    int t1, t2;
    for (int i = 1; i <= n; i++)
    {
        cin >> p >> t1;
        while (t1 != -1)
        {
            cin >> t2;
            v[p].push_back({t1, t2});
            cin >> t1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 1)
        {
            bfs(i);
            break;
        }
    }
    memset(visited, 0, sizeof(int) * (n + 1));
    bfs(endPoint);

    cout << longest << endl;
}
