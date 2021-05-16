#include <iostream>

using namespace std;

int parent[1000000];

int ufind(int u)
{
    if (u == parent[u])
        return u;

    int p = ufind(parent[u]);
    parent[u] = p;
    return p;
}

void uni(int u, int v)
{
    u = ufind(u);
    v = ufind(v);

    if (u != v)
        parent[v] = u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            uni(b, c);
        }
        else
        {
            if (ufind(b) == ufind(c))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}
