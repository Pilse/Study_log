#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> books_minus;
  vector<int> books_plus;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;

    if (t < 0)
    {
      books_minus.push_back(t);
      continue;
    }

    books_plus.push_back(t);
  }

  sort(books_plus.begin(), books_plus.end(), greater<>());
  sort(books_minus.begin(), books_minus.end());

  int cnt = 0;

  if (books_plus.empty() || books_minus.empty())
  {
    vector<int> &ref = books_plus.empty() ? books_minus : books_plus;

    cnt = abs(ref[0]);

    if (m >= ref.size())
    {
      cout << cnt << '\n';
      return 0;
    }

    for (int i = m; i < ref.size(); i += m)
      cnt += abs(ref[i]) * 2;

    cout << cnt << '\n';
    return 0;
  }

  vector<int> &longer = books_plus[0] > -books_minus[0] ? books_plus : books_minus;
  vector<int> &shorter = books_plus[0] <= -books_minus[0] ? books_plus : books_minus;

  cnt += abs(longer[0]);

  if (m < longer.size())
  {
    for (int i = m; i < longer.size(); i += m)
      cnt += abs(longer[i]) * 2;
  }

  for (int i = 0; i < shorter.size(); i += m)
    cnt += abs(shorter[i]) * 2;

  cout << cnt << '\n';
}
