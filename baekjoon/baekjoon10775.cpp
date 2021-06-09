#include <iostream>

using namespace std;

int parent[100001];

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        if (x > y)
            swap(x, y);
        parent[y] = x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int g, p;
    int cnt = 0;
    cin >> g >> p;

    for (int i = 1; i <= g; i++)
        parent[i] = i;

    for (int i = 1; i <= p; i++)
    {
        int t;
        cin >> t;

        int next = Find(t);
        if (next != 0)
        {
            Union(next, next - 1);
            cnt++;
        }
        else
            break;
    }
    cout << cnt << '\n';
}
