#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  map<string, int> m;
  int n;
  int cnt = 0;
  int arr[1001];
  string str;

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> str;

    m.insert({str, i});
  }

  for (int i = 1; i <= n; i++)
  {
    cin >> str;

    arr[i] = m[str];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (arr[i] > arr[j])
      {
        cnt++;
        break;
      }
    }
  }

  cout << cnt << '\n';
}
