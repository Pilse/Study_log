#include <iostream>
#include <vector>

using namespace std;

void get_cases(int n, int cur, int sum, string str, vector<string> &vec);
bool is_zero(string str);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    vector<string> vec;
    get_cases(n, 2, 1, "1", vec);

    for (string &v : vec)
      if (is_zero(v))
        cout << v << '\n';
    cout << '\n';
  }
}

void get_cases(int n, int cur, int sum, string str, vector<string> &vec)
{
  if (cur == n + 1)
  {
    vec.push_back(str);
    return;
  }
  get_cases(n, cur + 1, sum < 0 ? sum * 10 - cur : sum * 10 + cur, str + " " + to_string(cur), vec);
  get_cases(n, cur + 1, sum + cur, str + "+" + to_string(cur), vec);
  get_cases(n, cur + 1, sum - cur, str + "-" + to_string(cur), vec);
}

bool is_zero(string str)
{
  int sum = 0;
  int cur = 1;
  for (int i = 1; i < str.length(); i += 2)
  {
    int num = (i + 1) / 2 + 1;
    if (str[i] == '+')
    {
      if (cur != 0)
      {
        sum += cur;
        cur = 0;
      }
      cur = num;
      continue;
    }

    if (str[i] == '-')
    {
      if (cur != 0)
      {
        sum += cur;
        cur = 0;
      }
      cur = -num;
      continue;
    }

    cur = cur < 0 ? cur * 10 - num : cur * 10 + num;
  }

  sum += cur;
  return sum == 0;
}
