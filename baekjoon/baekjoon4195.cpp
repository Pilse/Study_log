#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

map<string, pair<int, int> > m;
pair<int, int> parent[300010];

int Find(int x)
{
    if (x == parent[x].first)
        return x;

    return parent[x].first = Find(parent[x].first);
}

int Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        parent[y].first = x;
        parent[x].second += parent[y].second;
    }
    return parent[x].second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, f;
    string user1, user2;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int mapidx = 0;
        cin >> f;

        for (int i = 0; i <= f * 2 + 1; i++)
        {
            parent[i].first = i;
            parent[i].second = 1;
        }
        for (int i = 0; i < f; i++)
        {
            int idx1, idx2;

            cin >> user1 >> user2;

            if (m.count(user1))
                idx1 = m[user1].second;
            else
            {
                m[user1] = {1, mapidx++};
                idx1 = m[user1].second;
            }

            if (m.count(user2))
                idx2 = m[user2].second;
            else
            {
                m[user2] = {1, mapidx++};
                idx2 = m[user2].second;
            }
            //cout << idx1 << " " << idx2;
            cout << Union(idx1, idx2) << '\n';
        }
    }
}
