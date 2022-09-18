#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void union_nodes(int x, int y, vector<int> &parent);
int find_node(int x, vector<int> &parent);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (m == 0)
    {
        cout << "YES" << '\n';
        return 0;
    }

    vector<int> parent(n);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int v;
            cin >> v;

            if (i < j && v)
                union_nodes(i, j, parent);
        }
    }

    vector<int> plans(m);
    for_each(plans.begin(), plans.end(), [](int &v)
             { cin >> v; });

    int base = find_node(plans[0] - 1, parent);

    for (int city : plans)
    {
        if (find_node(city - 1, parent) != base)
        {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
}

void union_nodes(int x, int y, vector<int> &parent)
{
    int px = find_node(x, parent);
    int py = find_node(y, parent);

    if (px == py)
        return;

    if (px > py)
        swap(px, py);
    parent[py] = px;
}

int find_node(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;

    return parent[x] = find_node(parent[x], parent);
}
