#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int a;
    int b;
    int c;
};

bool compare(node a, node b)
{
    return a.c < b.c;
}

vector<node> vec;
int parent[10100];

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

    int v, e;
    int a, b, c;
    int tot = 0;
    int cnt = 0;

    cin >> v >> e;

    for (int i = 1; i <= 10000; i++)
        parent[i] = i;

    while (e--)
    {
        cin >> a >> b >> c;
        node n = {a, b, c};
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < vec.size(); i++)
    {
        if (Union(vec[i].a, vec[i].b))
        {
            tot += vec[i].c;
            cnt++;
        }
        if (cnt == v - 1)
            break;
    }

    cout << tot << '\n';
}
