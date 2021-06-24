#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int s;
    int t;
};
struct compare
{
    bool operator()(node a, node b)
    {
        if (a.s == b.s)
            return a.t > b.t;
        return a.s > b.s;
    }
};

priority_queue<node, vector<node>, compare> pq;
priority_queue<int, vector<int>, greater<int> > result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int a, b;
    int end, cnt = 1;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        pq.push({a, b});
    }

    node t = pq.top();
    pq.pop();
    result.push(t.t);

    while (!pq.empty())
    {
        t = pq.top();
        pq.pop();
        while (!result.empty() && result.top() <= t.s)
        {
            result.pop();
        }
        result.push(t.t);

        cnt = max(cnt, (int)result.size());
    }

    cout << cnt << '\n';
}
