#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct coor
{
  int x;
  int y;
};

int distance_coor(coor a, coor b)
{
  return abs(a.y - b.y) + abs(a.x - b.x);
}

int road(coor cur, vector<pair<coor, int>> store, coor dest)
{
  if (distance_coor(cur, dest) <= 1000)
    return 1;

  queue<pair<coor, int>> q;

  for (int i = 0; i < store.size(); i++)
  {
    if (distance_coor(store[i].first, cur) <= 1000)
    {
      store[i].second = 1;
      q.push(store[i]);
    }
  }

  while (!q.empty())
  {
    coor _cur = q.front().first;

    q.pop();

    if (distance_coor(_cur, dest) <= 1000)
      return 1;

    for (int i = 0; i < store.size(); i++)
    {
      if (!store[i].second && distance_coor(_cur, store[i].first) <= 1000)
      {
        store[i].second = 1;
        q.push(store[i]);
      }
    }
  }

  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;

  cin >> tc;

  while (tc--)
  {
    int n;
    cin >> n;

    coor cur;
    cin >> cur.x >> cur.y;

    vector<pair<coor, int>> store;
    for (int i = 0; i < n; i++)
    {
      coor temp;
      cin >> temp.x >> temp.y;

      store.push_back({temp, 0});
    }

    coor dest;
    cin >> dest.x >> dest.y;

    if (road(cur, store, dest))
      cout << "happy" << '\n';
    else
      cout << "sad" << '\n';
  }
}
