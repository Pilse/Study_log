#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void immigration();
long long get_available_people_in_counter(long long time);

int Counter, People;
vector<long long> Counter_Time;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  immigration();
}

void input()
{
  cin >> Counter >> People;

  long long time_required;

  for (int i = 0; i < Counter; i++)
  {
    cin >> time_required;

    Counter_Time.push_back(time_required);
  }
}

void immigration()
{
  long long min_time = 0;

  sort(Counter_Time.begin(), Counter_Time.end());

  long long time_left_end = 0;
  long long time_right_end = Counter_Time[Counter_Time.size() - 1] * People;

  while (time_left_end <= time_right_end)
  {
    long long mid_time = (time_left_end + time_right_end) / 2;

    long long people_available = get_available_people_in_counter(mid_time);

    if (people_available >= People)
    {
      min_time = mid_time;

      time_right_end = mid_time - 1;
    }
    else
      time_left_end = mid_time + 1;
  }

  cout << min_time << '\n';
}

long long get_available_people_in_counter(long long time)
{
  long long people_available = 0;

  for (int i = 0; i < Counter_Time.size(); i++)
    people_available += time / Counter_Time[i];

  return people_available;
}
