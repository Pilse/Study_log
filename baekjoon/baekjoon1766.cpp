#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v[32001];
int refe[32001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int t1, t2;
    for (int i = 1; i <= m; i++)
    {
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        refe[t2]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (refe[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int p = pq.top();
        pq.pop();

        cout << p << " ";

        for (int i = 0; i < v[p].size(); i++)
        {
            int w = v[p][i];
            if (--refe[w] == 0)
                pq.push(w);
        }
    }
}
