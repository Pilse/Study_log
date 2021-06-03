#include <iostream>
#include <vector>

using namespace std;
int visited[100001];
int rev_visited[100001];
vector<int> referenced;

void dfs(int n, vector<int> v[])
{
    visited[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int w = v[n][i];
        if (!visited[w])
            dfs(w, v);
    }
    referenced.push_back(n);
}

void rev_dfs(int n, vector<int> v[])
{
    rev_visited[n] = 1;
    for (int i = 0; i < v[n].size(); i++)
    {
        int w = v[n][i];
        if (!rev_visited[w])
            rev_dfs(w, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++)
    {
        int n, m;
        int cnt = 0;
        cin >> n >> m;
        vector<int> v[100001];

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i, v);
            }
        }
        for (int i = referenced.size() - 1; i >= 0; i--)
        {

            if (!rev_visited[referenced[i]])
            {
                rev_dfs(referenced[i], v);
                cnt++;
            }
        }
        vector<int>().swap(referenced);
        fill(visited, visited + n + 1, 0);
        fill(rev_visited, rev_visited + n + 1, 0);
        cout << cnt << '\n';
    }
}
