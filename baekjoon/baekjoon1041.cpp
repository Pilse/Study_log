#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n;
  long long dim3_min = 1e9, dim2_min = 1e9, dim1_min = 1e9;
  long long dim3_cnt, dim2_cnt, dim1_cnt;
  int dim1_max = 0, sum = 0;

  vector<int> dice(6);
  vector<vector<int>> dim3;
  vector<vector<int>> dim2;

  cin >> n;

  dim3_cnt = 4;
  dim2_cnt = 8 * (n - 2) + 4;
  dim1_cnt = n * n * 5 - dim3_cnt * 3 - dim2_cnt * 2;

  for (auto &d : dice)
  {
    cin >> d;
    dim1_min = min(dim1_min, (long long)d);
    dim1_max = max(dim1_max, d);
    sum += d;
  }

  if (n == 1)
  {
    cout << sum - dim1_max << '\n';
    return 0;
  }

  dim3.push_back(vector<int>({1, 1, 1, 0, 0, 0}));
  dim3.push_back(vector<int>({1, 1, 0, 1, 0, 0}));
  dim3.push_back(vector<int>({1, 0, 0, 1, 1, 0}));
  dim3.push_back(vector<int>({1, 0, 1, 0, 1, 0}));
  dim3.push_back(vector<int>({0, 1, 1, 0, 0, 1}));
  dim3.push_back(vector<int>({0, 1, 0, 1, 0, 1}));
  dim3.push_back(vector<int>({0, 0, 0, 1, 1, 1}));
  dim3.push_back(vector<int>({0, 0, 1, 0, 1, 1}));

  dim2.push_back(vector<int>({1, 1, 0, 0, 0, 0}));
  dim2.push_back(vector<int>({1, 0, 1, 0, 0, 0}));
  dim2.push_back(vector<int>({1, 0, 0, 1, 0, 0}));
  dim2.push_back(vector<int>({1, 0, 0, 0, 1, 0}));
  dim2.push_back(vector<int>({0, 1, 1, 0, 0, 0}));
  dim2.push_back(vector<int>({0, 1, 0, 1, 0, 0}));
  dim2.push_back(vector<int>({0, 1, 0, 0, 0, 1}));
  dim2.push_back(vector<int>({0, 0, 1, 0, 1, 0}));
  dim2.push_back(vector<int>({0, 0, 1, 0, 0, 1}));
  dim2.push_back(vector<int>({0, 0, 0, 1, 1, 0}));
  dim2.push_back(vector<int>({0, 0, 0, 1, 0, 1}));
  dim2.push_back(vector<int>({0, 0, 0, 0, 1, 1}));

  for (auto dim : dim3)
  {
    long long sum = 0;

    for (int i = 0; i < dim.size(); i++)
      if (dim[i])
        sum += dice[i];

    dim3_min = min(dim3_min, sum);
  }

  for (auto dim : dim2)
  {
    long long sum = 0;

    for (int i = 0; i < dim.size(); i++)
      if (dim[i])
        sum += dice[i];

    dim2_min = min(dim2_min, sum);
  }

  cout << dim1_min * dim1_cnt + dim2_min * dim2_cnt + dim3_min * dim3_cnt << '\n';
}
