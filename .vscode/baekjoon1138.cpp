#include <iostream>

using namespace std;

int n;
int arr[11];
int visited[11];

void search()
{
  for (int i = 1; i <= n; i++)
  {
    if (!arr[i] && !visited[i])
    {
      visited[i] = 1;

      cout << i << " ";

      for (int j = 1; j < i; j++)
        arr[j] -= 1;

      search();

      break;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  search();
}
