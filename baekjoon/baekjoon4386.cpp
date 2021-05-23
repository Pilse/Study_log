#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int parent[110];

struct node
{
    double x;
    double y;
};
struct edge
{
    int a;
    int b;
    double d;
};

vector<edge> v;
map<int, node> m;

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

int Union(edge a)
{
    int x = Find(a.a);
    int y = Find(a.b);

    if (x != y)
    {
        if (x > y)
            swap(x, y);
        parent[y] = x;
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    double x, y;
    int cnt = 0;
    double tot = 0;
    int termination = 0;

    for (int i = 0; i <= 100; i++)
    {
        parent[i] = i;
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        m[i] = {x, y};
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            v.push_back({i, j, distance_btw_stars(m[i], m[j])});
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        if (Union(v[i]))
        {
            cnt++;
            tot += v[i].d;
        }
        if (cnt == n - 1)
        {
            termination = 1;
            break;
        }
    }

    cout << round(tot * 100) / 100 << '\n';
}
