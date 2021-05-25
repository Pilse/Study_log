#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct coor
{
    int y;
    int x;
    int w;
    int h;
};
struct edge
{
    int a;
    int b;
    int d;
};

int parent[10];
int arr[11][11];
int y, x;
map<int, coor> m;
vector<edge> v;

bool cmp(edge a, edge b)
{
    return a.d < b.d;
}

int getDistance(coor a, coor b)
{
    int lowestXa = a.x;
    int lowestXb = b.x;
    int lowestYa = a.y;
    int lowestYb = b.y;
    int highestXa = min(a.x + a.w - 1, x);
    int highestXb = min(b.x + b.w - 1, x);
    int highestYa = min(a.y + a.h - 1, y);
    int highestYb = min(b.y + b.h - 1, y);

    cout << a.x << a.y << lowestXa << highestXa << lowestYa << highestYa << '\n';
    cout << b.x << b.y << lowestXb << highestXb << lowestYb << highestYb << '\n';

    for (int i = 0; i < b.h; i++)
    {
        if (b.y + i >= lowestYa && b.y + i <= highestYa)
        {
            return max(lowestXa - highestXb - 1, lowestXb - highestXa - 1);
        }
    }
    for (int i = 0; i < b.w; i++)
    {
        if (b.x + i >= lowestXa && b.x + i <= highestXa)
        {
            return max(lowestYa - highestYb - 1, lowestYb - highestYa - 1);
        }
    }
    return 1;
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

    for (int i = 0; i < 9; i++)
        parent[i] = i;

    int cnt = 0;
    int tot = 0;
    int valid = 0;

    cin >> y >> x;

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
                {
                    m[++cnt] = {i, j, 1, 1};
                    arr[i][j] = cnt;
                }
                else if (arr[i - 1][j] && arr[i][j - 1] == 0)
                {
                    m[arr[i - 1][j]].h++;
                    arr[i][j] = arr[i - 1][j];
                }
                else if (arr[i - 1][j] == 0 && arr[i][j - 1])
                {
                    m[arr[i][j - 1]].w++;
                    arr[i][j] = arr[i][j - 1];
                }
                else
                {
                    if (arr[i - 1][j] != arr[i][j - 1])
                    {
                        int tw = m[arr[i][j - 1]].w;
                        int th = m[arr[i][j - 1]].h;
                        int tx = j;
                        while (arr[i][tx - 1] == 0)
                        {
                            arr[i][tx - 1] = arr[i - 1][j];
                            tx--;
                        }
                        cnt--;
                        m[arr[i - 1][j]].w += tw;
                        m[arr[i - 1][j]].h += th;
                        arr[i][j - 1] = arr[i - 1][j];
                        arr[i][j] = arr[i - 1][j];
                    }
                    else
                        arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }

    for (int i = 1; i <= cnt - 1; i++)
    {
        for (int j = i + 1; j <= cnt; j++)
        {
            int dist = getDistance(m[i], m[j]);
            if (dist > 1)
                v.push_back({i, j, dist});
        }
    }

    //    if(v.size() < cnt - 1)
    //    {
    //        cout << -1 <<'\n';
    //        return 0;
    //    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].a << " " << v[i].b << " " << v[i].d << '\n';
    }
    for (int i = 1; i <= cnt; i++)
    {
        cout << m[i].y << " " << m[i].x << " " << m[i].h << " " << m[i].w << " " << '\n';
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (Union(v[i].a, v[i].b))
        {
            valid++;
            tot += v[i].d;
        }
        if (valid == cnt - 1)
        {
            cout << tot << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
