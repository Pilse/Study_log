#include <iostream>
#include <queue>
#define MAX_POS 100000
#define MIN_POS 0

using namespace std;

void input();
void hide_and_seek();
bool can_visit(int position, int step);

int Source, Target;
int Visited[100001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  hide_and_seek();
}

void input()
{
  cin >> Source >> Target;
}

void hide_and_seek()
{
  deque<pair<int, int> > q;

  Visited[Source] = 1;

  q.push_back({Source, 1});

  while (!q.empty())
  {
    int current_position = q.front().first;
    int current_step = q.front().second;

    q.pop_front();

    if (current_position == Target)
    {
      cout << current_step - 1 << '\n';
      return;
    }

    int next_position = current_position * 2;
    if (can_visit(next_position, current_step))
    {
      Visited[next_position] = current_step;

      q.push_front({next_position, current_step});

      next_position *= 2;
    }

    next_position = current_position + 1;
    if (can_visit(next_position, current_step))
    {
      Visited[next_position] = current_step + 1;

      q.push_back({next_position, current_step + 1});
    }

    next_position = current_position - 1;
    if (can_visit(next_position, current_step))
    {
      Visited[next_position] = current_step + 1;

      q.push_back({next_position, current_step + 1});
    }
  }
}

bool can_visit(int position, int step)
{
  if (position >= MIN_POS && position <= MAX_POS && (!Visited[position] || Visited[position] > step || position == Target))
    return true;
  else
    return false;
}
