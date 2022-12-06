#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int p, d;
  vector<int> schedule(10001, 0);
  vector<pair<int, int>> offer;
  while (n--)
  {
    cin >> p >> d;
    offer.push_back({d, p});
  }

  int sum = 0;
  sort(offer.begin(), offer.end());
  for (auto [day, pay] : offer)
  {
    if (schedule[day] > pay)
      continue;

    int min_day = 1;
    int min_pay = schedule[min_day];
    for (int i = 2; i <= day; i++)
    {
      if (schedule[i] >= min_pay)
        continue;

      min_pay = schedule[i];
      min_day = i;
    }

    sum += pay - min_pay;
    schedule[min_day] = pay;
  }

  cout << sum << '\n';
}
