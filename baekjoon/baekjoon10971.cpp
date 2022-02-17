#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

void input();
void traversal(int src, int city, int cost, int cnt);

int N, Min_Cost = 987654321;
int Cities[10][10];
int Visited[10];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  for (int i = 0; i < N; i++)
  {
    Visited[i] = 1;

    traversal(i, i, 0, 0);

    Visited[i] = 0;
  }

  cout << Min_Cost << '\n';
}

void input()
{
  cin >> N;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> Cities[i][j];
}

void traversal(int src, int city, int cost, int cnt)
{
  if (cnt == N - 1)
  {
    if (Cities[city][src])
      Min_Cost = min(Min_Cost, cost + Cities[city][src]);

    return;
  }

  for (int i = 0; i < N; i++)
  {
    if (Cities[city][i] && !Visited[i])
    {
      Visited[city] = 1;

      traversal(src, i, cost + Cities[city][i], cnt + 1);

      Visited[city] = 0;
    }
  }
}
