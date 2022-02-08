#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
pair<int, int> search(vector<int> vec);

int N;
vector<int> Vec;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  sort(Vec.begin(), Vec.end());

  pair<int, int> point = search(Vec);

  cout << point.first << " " << point.second << '\n';
}

void input()
{
  cin >> N;
  ;

  for (int i = 0; i < N; i++)
  {
    int n;

    cin >> n;

    Vec.push_back(n);
  }
}

pair<int, int> search(vector<int> vec)
{
  int start = 0;
  int end = (int)Vec.size() - 1;

  int answer_start = start;
  int answer_end = end;

  int current_sum = vec[start] + vec[end];

  while (start < end)
  {
    if (vec[start] + vec[end] == 0)
    {
      answer_start = start;
      answer_end = end;
      break;
    }

    if (abs(current_sum) > abs(vec[start] + vec[end]))
    {
      answer_start = start;
      answer_end = end;
      current_sum = vec[start] + vec[end];
    }

    if (vec[start] + vec[end] > 0)
      end--;

    else
      start++;
  }

  return {vec[answer_start], vec[answer_end]};
}
