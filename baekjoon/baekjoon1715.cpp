#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int> > pq;
    int n, t;
    int tot = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        pq.push(t);
    }

    while (pq.size() != 1)
    {
        int p1;
        int p2;

        p1 = pq.top();
        pq.pop();
        p2 = pq.top();
        pq.pop();

        int sum = p1 + p2;
        tot += sum;
        pq.push(sum);
    }
    cout << tot << '\n';
}
