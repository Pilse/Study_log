#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<int, vector<int>, less<int> > sum;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k, t;
  int result = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> t;
    pq.push(t);
  }

  int pre, cur;
  cur = pq.top();
  pq.pop();

  while (!pq.empty())
  {
    pre = cur;
    cur = pq.top();
    pq.pop();

    sum.push(cur - pre);
  }
  while (!sum.empty() && k > 1)
  {
    sum.pop();
    k--;
  }
  while (!sum.empty())
  {
    t = sum.top();
    sum.pop();
    result += t;
  }

  cout << result << '\n';
}
