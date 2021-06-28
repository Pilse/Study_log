#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long num1, num2;
    long long sum;
    long long t;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        pq.push(t);
    }
    while (m--)
    {
        num1 = pq.top();
        pq.pop();
        num2 = pq.top();
        pq.pop();
        sum = num1 + num2;
        pq.push(sum);
        pq.push(sum);
    }

    sum = 0;

    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << '\n';
}
