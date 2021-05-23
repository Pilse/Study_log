#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int parent[1010];

struct node
{
    int x;
    int y;
};
struct edge
{
    int a;
    int b;
    double d;
};

bool cmp(edge a, edge b)
{
    return a.d < b.d;
}

double distance_btw_stars(node a, node b)
{
    double pow_x = pow(a.x - b.x, 2);
    double pow_y = pow(a.y - b.y, 2);
    double distance = sqrt(pow_x + pow_y);

    return distance;
}

int Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

int Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        if (x > y)
            swap(x, y);
        parent[y] = x;
        return 1;
    }
    return 0;
}

map<int, node> m;
map<pair<int, int>, double> ma2;
vector<edge> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 1000; i++)
        parent[i] = i;

    int n, ma;
    int x, y;
    int a, b;
    double tot = 0;
    int cnt = 0;

    cin >> n >> ma;

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        m[i] = {x, y};
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double dist = distance_btw_stars(m[i], m[j]);
            v.push_back({i, j, dist});
            ma2[{i, j}] = dist;
        }
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= ma; i++)
    {
        cin >> a >> b;

        if (Union(a, b))
            cnt++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (cnt == n - 1)
            break;
        if (Union(v[i].a, v[i].b))
        {
            cnt++;
            tot += v[i].d;
        }
        if (cnt == n - 1)
            break;
    }

    cout << fixed;
    cout.precision(2);
    cout << round(tot * 100) / 100 << '\n';
}
