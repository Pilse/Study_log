#include <iostream>
#include <vector>

using namespace std;

void input();
void search();

int N, M;
vector<int> Arr;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  search();
}

void input()
{
  cin >> N >> M;

  for (int i = 0; i < N; i++)
  {
    int temp;

    cin >> temp;

    Arr.push_back(temp);
  }
}

void search()
{
  int cnt = 0;

  int left = 0;
  int right = 0;

  while (left < N)
  {
    int sum = 0;

    if (left == right)
      sum = Arr[left];
    else
    {
      for (int i = left; i <= right; i++)
        sum += Arr[i];
    }

    if (sum == M)
      cnt++;

    if (sum >= M)
      left++;
    else
    {
      if (right == N - 1)
        left++;
      else
        right++;
    }
  }

  cout << cnt << '\n';
}
