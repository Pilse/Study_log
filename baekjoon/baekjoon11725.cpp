#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
queue<pair<int, int> > q;
int visited[100001];
int parent[100001];

void bfs()
{
    for (int i = 0; i < v[1].size(); i++)
    {
        q.push({v[1][i], 1});
        visited[v[1][i]] = 1;
    }

    while (!q.empty())
    {
        int w = q.front().first;
        int p = q.front().second;

        q.pop();

        parent[w] = p;

        for (int i = 0; i < v[w].size(); i++)
        {
            int r = v[w][i];
            if (!visited[r])
            {
                q.push({r, w});
                visited[r] = 1;
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

    int t1, t2;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }

    bfs();

    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}
