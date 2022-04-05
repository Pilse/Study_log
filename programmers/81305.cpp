#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

int x[10001];
int l[10001];
int r[10001];
int p[10001];
int root;

using namespace std;

int dfs(int cur, int mid, int &cnt)
{
  int lv = 0;
  if (l[cur] != -1)
    lv = dfs(l[cur], mid, cnt);

  int rv = 0;
  if (r[cur] != -1)
    rv = dfs(r[cur], mid, cnt);

  if (lv + rv + x[cur] <= mid)
  {
    return lv + rv + x[cur];
  }
  else if (min(lv, rv) + x[cur] <= mid)
  {
    cnt++;
    return min(lv, rv) + x[cur];
  }
  else
  {
    cnt += 2;
    return x[cur];
  }
}

bool check(int mid, int limit)
{
  int cnt = 0;

  dfs(root, mid, cnt);

  if (cnt <= limit - 1)
    return true;
  return false;
}

int solution(int k, vector<int> num, vector<vector<int> > links)
{
  memset(p, -1, sizeof(p));
  int st = -1, en = 0, mid;

  for (int i = 0; i < num.size(); i++)
  {
    x[i] = num[i];
    l[i] = links[i][0];
    r[i] = links[i][1];
    if (links[i][0] != -1)
      p[links[i][0]] = i;
    if (links[i][1] != -1)
      p[links[i][1]] = i;

    st = max(st, num[i]);
    en += num[i];
  }

  for (int i = 0; i < num.size(); i++)
  {
    if (p[i] == -1)
    {
      root = i;
      break;
    }
  }

  int ans = 0;

  while (st <= en)
  {
    mid = (st + en) / 2;

    if (check(mid, k))
    {
      ans = mid;
      en = mid - 1;
    }
    else
    {
      st = mid + 1;
    }
  }

  return ans;
}