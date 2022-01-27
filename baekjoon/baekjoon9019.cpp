#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

void input();
void bfs(int src, int trg);
int d(int n);
int s(int n);
int l(int n);
int r(int n);

int T;
char Command[4] = {'D', 'S', 'L', 'R'};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  int source, target;

  for (int i = 0; i < T; i++)
  {
    cin >> source >> target;

    bfs(source, target);
  }
}

void input()
{
  cin >> T;
}

void bfs(int src, int trg)
{
  int visited[10005];
  string str;
  queue<pair<int, string> > q;

  memset(visited, 0, sizeof(visited));

  visited[src] = 1;

  q.push({src, str});

  while (!q.empty())
  {
    int cur_number = q.front().first;
    string cur_commands = q.front().second;

    q.pop();

    if (cur_number == trg)
    {
      cout << cur_commands;

      cout << '\n';

      return;
    }

    for (int i = 0; i < 4; i++)
    {
      int n_number;

      if (i == 0)
        n_number = d(cur_number);
      else if (i == 1)
        n_number = s(cur_number);
      else if (i == 2)
        n_number = l(cur_number);
      else
        n_number = r(cur_number);

      if (n_number <= 10000 && n_number >= 0 && !visited[n_number])
      {
        visited[n_number] = 1;

        if (i == 0)
          q.push({n_number, cur_commands + 'D'});
        else if (i == 1)
          q.push({n_number, cur_commands + 'S'});
        else if (i == 2)
          q.push({n_number, cur_commands + 'L'});
        else
          q.push({n_number, cur_commands + 'R'});
      }
    }
  }
}

int d(int n)
{
  return (2 * n) % 10000;
}

int s(int n)
{
  return n == 0 ? 9999 : n - 1;
}

int l(int n)
{
  bool condition = 0;

  if (n >= 1000)
    condition = true;

  if (condition)
  {
    int temp = n / 1000;
    n *= 10;
    n -= temp * 10000;
    n += temp;

    return n;
  }
  else
    return n * 10;
}

int r(int n)
{
  int low = n % 10;

  n /= 10;
  n += low * 1000;

  return n;
}
