#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<vector<int> > adj;
vector<vector<int> > radj;
vector<bool> visited;

void dfs(int here, vector<int> &rpath)
{
    if (visited[here])
        return;
    visited[here] = true;

    for (int i = 0; i < adj[here].size(); i++)
    {
        int next = adj[here][i];
        dfs(next, rpath);
    }
    rpath.push_back(here);
}

void makeSCC(int here, vector<int> &path)
{
    if (visited[here])
        return;
    visited[here] = true;
    path.push_back(here);

    for (int i = 0; i < radj[here].size(); i++)
    {
        int next = radj[here][i];
        makeSCC(next, path);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    adj.assign(V + 1, vector<int>());
    radj.assign(V + 1, vector<int>());
    visited.assign(V + 1, false);

    vector<int> path;
    vector<int> rpath;

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (int i = 1; i < radj.size(); i++)
    {
        dfs(i, rpath);
    }

    visited.assign(V + 1, false);

    vector<vector<int> > result;

    for (int i = rpath.size() - 1; i >= 0; i--)
    {
        int cur = rpath[i];
        makeSCC(cur, path);
        if (!path.empty())
        {
            sort(path.begin(), path.end());
            result.push_back(path);
        }
        path.clear();
    }
    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        for (const auto &el : result[i])
        {
            cout << el << ' ';
        }
        cout << "-1\n";
    }

    return 0;
}
