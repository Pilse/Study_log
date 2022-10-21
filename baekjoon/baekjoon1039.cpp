#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  if (n < 10)
  {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> result;
  result.push_back(n);

  vector<int> nums;
  string str = to_string(n);
  transform(str.begin(), str.end(), back_inserter(nums), [](char c)
            { return c - '0'; });

  while (k--)
  {
    vector<int> combs;
    vector<int> candidates;
    for (int i = 0; i < nums.size() - 2; i++)
      combs.push_back(0);
    for (int i = 0; i < 2; i++)
      combs.push_back(1);

    do
    {
      vector<int> idx;
      for (int t = 0; t < combs.size(); t++)
        if (combs[t])
          idx.push_back(t);

      int i = idx[0];
      int j = idx[1];

      for (auto number : result)
      {
        vector<int> temp_nums;
        string str = to_string(number);
        transform(str.begin(), str.end(), back_inserter(temp_nums), [](char c)
                  { return c - '0'; });

        if (i == 0 && temp_nums[j] == 0)
          continue;

        vector<int> temp = temp_nums;
        swap(temp[i], temp[j]);

        string temp_str(temp.size(), '0');
        transform(temp.begin(), temp.end(), temp_str.begin(), [](int v)
                  { return v + '0'; });

        candidates.push_back(stoi(temp_str));
      }
    } while (next_permutation(combs.begin(), combs.end()));
    vector<int>().swap(result);
    if (candidates.size() == 0)
      break;

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    copy(candidates.begin(), candidates.end(), back_inserter(result));
  }

  if (result.size() == 0)
  {
    cout << -1 << '\n';
    return 0;
  }

  sort(result.begin(), result.end(), greater<>());
  cout << result[0] << '\n';
}
