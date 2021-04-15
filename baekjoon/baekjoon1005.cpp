#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v[1001];
        queue<pair<int, int> > q;
        int ref[1001] = {
            0,
        };
        int cost[1001] = {
            0,
        };
        int cmp[1001] = {
            0,
        };

        for (int j = 1; j <= n; j++)
            cin >> cost[j];

        for (int j = 0; j < k; j++)
        {
            int t1, t2;
            cin >> t1 >> t2;

            v[t1].push_back(t2);
            ref[t2]++;
        }

        int obj;
        cin >> obj;

        for (int j = 1; j <= n; j++)
        {
            if (ref[j] == 0)
                q.push({j, cost[j]});
        }

        while (!q.empty())
        {
            int p = q.front().first;
            int curCost = q.front().second;
            q.pop();
            //cout<<curCost<<" ";

            if (p == obj)
            {
                cout << curCost << '\n';
                break;
            }

            for (int j = 0; j < v[p].size(); j++)
            {
                int w = v[p][j];

                if (--ref[w] == 0)
                    q.push({w, max(cmp[w], curCost + cost[w])});

                else
                    cmp[w] = max(cmp[w], curCost + cost[w]);
            }
        }
    }
}
