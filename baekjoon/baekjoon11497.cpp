#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int> > pq;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, n, a;
  int num;
  cin >> t;

  while (t--)
  {
    cin >> n;
    int arr[10001];
    int max_sub = -1;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      pq.push(a);
    }
    int center = (n + 1) / 2;
    int flag = 0;
    int idx = 1;

    num = pq.top();
    pq.pop();
    arr[center] = num;

    while (!pq.empty())
    {
      num = pq.top();
      pq.pop();

      if (!flag)
      {
        arr[center - idx] = num;
        max_sub = max(max_sub, abs(num - arr[center - idx + 1]));
        flag = 1;
        //                cout << num << arr[center - idx + 1] <<" ";
      }
      else if (flag)
      {
        arr[center + idx] = num;
        max_sub = max(max_sub, abs(num - arr[center + idx - 1]));
        flag = 0;
        //                cout << num<< arr[center + idx - 1] << " ";
        idx++;
      }
    }

    cout << max_sub << '\n';
  }
}
