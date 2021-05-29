#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, less<int> > pq1;
    priority_queue<int, vector<int>, greater<int> > pq2;
    int n, t;
    int p1, p2;
    int idx = 0;
    int tot = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t == 1)
            tot++;
        else if (t > 1)
            pq1.push(t);
        else
            pq2.push(t);
    }

    while (!pq1.empty())
    {
        p1 = pq1.top();
        pq1.pop();

        if (pq1.empty())
        {
            tot += p1;
            break;
        }

        p2 = pq1.top();
        pq1.pop();

        tot += p1 * p2;
    }
    while (!pq2.empty())
    {
        p1 = pq2.top();
        pq2.pop();

        if (pq2.empty())
        {
            tot += p1;
            break;
        }

        p2 = pq2.top();
        pq2.pop();

        tot += p1 * p2;
    }

    cout << tot << '\n';
}
