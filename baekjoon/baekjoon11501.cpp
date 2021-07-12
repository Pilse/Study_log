#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc, n, stock;
  cin >> tc;

  while (tc--)
  {
    priority_queue<int, vector<int>, less<int> > pq;
    int arr[1000000];
    int rev = 0;
    int max_rev;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> stock;
      arr[i] = stock;
      pq.push(stock);
    }

    max_rev = pq.top();
    pq.pop();

    for (int j = 0; j < n; j++)
    {
      if (arr[j] > max_rev)
        continue;
      else if (arr[j] < max_rev)
        rev += arr[j];
      else
      {
        max_rev = pq.top();
        pq.pop();
      }
    }

    cout << rev << '\n';
  }
}
