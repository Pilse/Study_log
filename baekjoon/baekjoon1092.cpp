#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;

  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;
  sort(vec.begin(), vec.end(), greater<>());

  cin >> m;
  deque<int> dq;
  vector<int> boxes;
  for (int i = 0; i < m; i++)
  {
    int t;
    cin >> t;
    boxes.push_back(t);
  }
  sort(boxes.begin(), boxes.end(), greater<>());
  for (auto b : boxes)
    dq.push_back(b);

  if (vec[0] < dq.front())
  {
    cout << -1 << '\n';
    return 0;
  }

  int answer = 0;
  while (!dq.empty())
  {
    answer++;
    vector<int> temp;
    for (int i = 0; i < vec.size(); i++)
    {
      if (dq.empty())
        break;

      int w = dq.front();
      dq.pop_front();

      if (vec[i] < w)
      {
        temp.push_back(w);
        i--;
      }
    }
    for (int j = temp.size() - 1; j >= 0; j--)
      dq.push_front(temp[j]);
    vector<int>().swap(temp);
  }

  cout << answer << '\n';
}
