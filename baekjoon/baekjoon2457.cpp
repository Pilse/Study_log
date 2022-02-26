#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void find_number_of_flower();

int N;
vector<pair<int, int> > Calendar;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  sort(Calendar.begin(), Calendar.end());

  find_number_of_flower();
}

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int s1, s2, e1, e2;

    cin >> s1 >> s2 >> e1 >> e2;

    Calendar.push_back({s1 * 100 + s2, e1 * 100 + e2});
  }
}

void find_number_of_flower()
{
  if (Calendar[0].first > 301)
  {
    cout << 0 << '\n';
    return;
  }

  int start = 300;
  int end = 301;
  int idx = 0;
  int cnt = 0;

  int next_start = start;
  int next_end = end;
  int next_idx = idx;

  while (end <= 1131)
  {

    for (; idx < N; idx++)
    {
      int cur_start = Calendar[idx].first;
      int cur_end = Calendar[idx].second;

      if (cur_start <= end)
      {
        if (next_end < cur_end)
        {
          next_start = cur_start;
          next_end = cur_end;
          next_idx = idx;
        }
      }
      else
        break;
    }

    if (end == next_end)
      break;

    cnt++;
    start = next_start;
    end = next_end;
    idx = next_idx;
  }

  if (end >= 1131)
    cout << cnt << '\n';
  else
    cout << 0 << '\n';
}
