#include <iostream>
#include <vector>

using namespace std;

void input();
void lis();

int N;
int Arr[1001];
int Dp[1001];
vector<int> Vec[1001];
vector<int> Lis;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  lis();

  cout << Lis.size() << '\n';

  for (int i = 0; i < Lis.size(); i++)
    cout << Lis[i] << " ";
  cout << '\n';
}

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> Arr[i];
}

void lis()
{
  for (int i = 0; i < N; i++)
  {
    Vec[i].push_back(Arr[i]);
    Dp[i] = 1;

    for (int j = 0; j < i; j++)
    {
      if (Arr[i] > Arr[j] && Dp[i] < Dp[j] + 1)
      {
        Vec[i].clear();

        Vec[i] = Vec[j];

        Vec[i].push_back(Arr[i]);

        Dp[i] = Dp[j] + 1;
      }
    }

    if (Lis.size() < Vec[i].size())
      Lis = Vec[i];
  }
}
