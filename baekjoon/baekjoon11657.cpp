#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

vector<pair<long long, long long> > v[501];
long long arr[501];

void bellman(int n)
{
    arr[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < v[j].size(); k++)
            {
                long long d = v[j][k].first;
                long long w = v[j][k].second;

                if (arr[j] != INF && arr[w] > arr[j] + d)
                {
                    arr[w] = arr[j] + d;
                    if (i == n)
                    {
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == INF)
            cout << -1 << '\n';
        else
            cout << arr[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    fill_n(arr, n + 1, INF);

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }

    bellman(n);
}
