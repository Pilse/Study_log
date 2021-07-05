#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
  int d;
  int w;
};

vector<node> v;
node arr[1001];

bool cmp(node a, node b)
{
  if (a.w == b.w)
    return a.d > b.d;
  return a.w > b.w;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int a, b;
  int result = 0;
  int max_d = -1;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    v.push_back({a, b});
    max_d = max(max_d, a);
  }

  sort(v.begin(), v.end(), cmp);

  int s = v.size();
  int cnt = 0;
  while (s--)
  {
    int idx = v[cnt].d;

    if (arr[idx].w == 0)
      arr[idx].w = v[cnt].w;
    else
    {
      while (idx)
      {
        if (arr[idx].w == 0)
        {
          arr[idx].w = v[cnt].w;
          break;
        }
        idx--;
      }
    }
    cnt++;
  }
  for (int i = 1; i <= max_d; i++)
  {
    result += arr[i].w;
  }
  cout << result << '\n';
}
