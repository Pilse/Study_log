#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > q;
int parent[500000];

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

    if (x == y)
        return 1;
    else
    {
        if (y > x)
            swap(x, y);
        parent[y] = x;
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int dot1, dot2;
    int terminate_flag = 0;
    int first_cycle_num = 0;
    int idx = 0;

    cin >> n >> m;
    for (int i = 0; i < 500000; i++)
        parent[i] = i;

    while (m--)
    {
        cin >> dot1 >> dot2;
        q.push({dot1, dot2});
    }
    while (!q.empty())
    {
        idx++;

        dot1 = q.front().first;
        dot2 = q.front().second;
        q.pop();

        if (Union(dot1, dot2))
        {
            terminate_flag = 1;
            first_cycle_num = idx;
            break;
        }
    }
    if (terminate_flag)
        cout << first_cycle_num << '\n';
    else
        cout << 0 << '\n';
}
