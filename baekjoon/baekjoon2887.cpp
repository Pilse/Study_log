#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
struct coor
{
    int x;
    int y;
    int z;
};
short parent[100010];

bool cmp(coor a, coor b)
{
    return a.z < b.z;
}

map<int, coor> m;
vector<coor> v;

int distance(coor a, coor b)
{
    return min({abs(a.x - b.x), abs(a.y - b.y), abs(a.z - b.z)});
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 100005; i++)
        parent[i] = i;

    int n;
    int x, y, z;
    int cnt = 0;
    int tot = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        m[i] = {x, y, z};
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            v.push_back({i, j, distance(m[i], m[j])});
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        if (Union(v[i].x, v[i].y))
        {
            cnt++;
            tot += v[i].z;
        }
        if (cnt == n - 1)
            break;
    }
    cout << tot << '\n';
}
