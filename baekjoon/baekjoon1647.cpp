#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
  int x;
  int y;
  int cost;
};

int parent[100001];

bool compare(node a, node b);
int find_parent(int x);
int merge_parent(node a);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 입력받기
  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++)
    parent[i] = i;

  vector<node> v;
  node temp;
  for (int i = 0; i < m; i++)
  {
    cin >> temp.x >> temp.y >> temp.cost;
    v.push_back(temp);
  }

  // 풀이
  sort(v.begin(), v.end(), compare);

  int cnt = 0, tot = 0;
  for (int i = 0; i < m; i++)
  {
    if (cnt == n - 2)
      break;

    if (merge_parent(v[i]))
    {
      tot += v[i].cost;
      cnt++;
    }
  }

  cout << tot << '\n';
}

// 함수 정의
bool compare(node a, node b)
{
  return a.cost < b.cost;
}

int find_parent(int x)
{
  if (x == parent[x])
    return x;

  return find_parent(parent[x]);
}

int merge_parent(node a)
{
  int x = find_parent(a.x);
  int y = find_parent(a.y);

  if (x != y)
  {
    if (x > y)
      swap(x, y);

    parent[y] = x;
    return 1;
  }

  return 0;
}
