#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, l;
int w[1001];
priority_queue<int, vector<int>, greater<> > q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    int t;
    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        w[t] = 1;
        q.push(t);
    }

    while (!q.empty())
    {
        int p = q.top();
        q.pop();

        if (w[p])
        {
            tot++;
            for (int i = p; i < min(p + l, 1001); i++)
                w[i] = 0;
        }
    }

    cout << tot << '\n';
}
