#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32001];
int result[32001];
int cnt[32001];
queue<int> q;

void line(int n)
{
    int idx{};

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        result[idx++] = p;

        for (int i = 0; i < v[p].size(); i++)
        {
            int w = v[p][i];

            if (--cnt[w] == 0)
                q.push(w);
        }
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int t1, t2;

    for (int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        v[t1].push_back(t2);
        cnt[t2]++;
    }

    line(n);
}
