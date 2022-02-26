#include <iostream>
#include <queue>

struct emoji
{
  int screen;
  int copied;
  int step;
};

using namespace std;

void input();
void copy_and_paste();

int Target;
int Visited[1001][1001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  copy_and_paste();
}

void input()
{
  cin >> Target;
}

void copy_and_paste()
{
  queue<emoji> q;

  Visited[1][0] = 1;

  q.push({1, 0, 0});

  while (!q.empty())
  {
    int current_screen = q.front().screen;
    int current_copied = q.front().copied;
    int current_step = q.front().step;

    q.pop();

    if (current_screen > Target)
      continue;

    if (current_screen == Target)
    {
      cout << current_step << '\n';
      return;
    }

    if (current_screen > 0 && current_screen * 2 <= 1000 && !Visited[current_screen][current_screen])
    {
      Visited[current_screen][current_screen] = 1;
      q.push({current_screen, current_screen, current_step + 1});
    }

    if (current_screen > 0 && current_screen + current_copied <= 1000 && !Visited[current_screen + current_copied][current_copied])
    {
      Visited[current_screen + current_copied][current_copied] = 1;
      q.push({current_screen + current_copied, current_copied, current_step + 1});
    }

    if (current_screen > 0 && !Visited[current_screen - 1][current_copied])
    {
      Visited[current_screen - 1][current_copied] = 1;
      q.push({current_screen - 1, current_copied, current_step + 1});
    }
  }
}
