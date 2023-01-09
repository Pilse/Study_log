#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct post
{
  int pos;
  int pop;
};

long long get_distance(vector<post> &v, int from);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<post> v;
  vector<long long> sum;
  long long n, answer = 0, min_diff = LONG_LONG_MAX;

  cin >> n;

  sum.resize(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    post p;
    cin >> p.pos >> p.pop;
    v.push_back(p);
  }

  sort(v.begin(), v.end(), [](post a, post b)
       { return a.pos < b.pos; });

  for (int i = 0; i < v.size(); i++)
    sum[i + 1] = sum[i] + v[i].pop;

  for (int i = 1; i < sum.size(); i++)
  {
    long long diff = abs(sum[i - 1] - (sum[n] - sum[i]));

    if (min_diff > diff)
    {
      min_diff = diff;
      answer = v[i - 1].pos;
    }
  }

  cout << answer << '\n';
}
