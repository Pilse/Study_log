#include <iostream>
#include <queue>
#define MAX_LIMIT 100000
#define MIN_LIMIT 0

using namespace std;

void input();
void init_condition();
void find_way(int src);
bool can_visit(int position, int time);
bool is_timeout(int time);
bool is_target(int position);
void update_result(int time);

int Source, Target;
int Min_Time, Cnt;
int Visited[100001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  init_condition();

  find_way(Source);

  cout << Min_Time << '\n'
       << Cnt << '\n';
}

void input()
{
  cin >> Source >> Target;
}

void init_condition()
{
  Min_Time = abs(Target - Source);
}

void find_way(int src)
{
  Visited[src] = 1;

  queue<pair<int, int> > q;

  q.push({src, 0});

  while (!q.empty())
  {
    int cur_pos = q.front().first;
    int cur_time = q.front().second;

    q.pop();

    if (is_timeout(cur_time))
      continue;

    if (is_target(cur_pos))
    {
      update_result(cur_time);

      continue;
    }

    if (can_visit(cur_pos + 1, cur_time + 1))
    {
      Visited[cur_pos + 1] = cur_time + 1;

      q.push({cur_pos + 1, cur_time + 1});
    }

    if (can_visit(cur_pos - 1, cur_time + 1))
    {
      Visited[cur_pos - 1] = cur_time + 1;

      q.push({cur_pos - 1, cur_time + 1});
    }

    if (can_visit(cur_pos * 2, cur_time + 1))
    {
      Visited[cur_pos * 2] = cur_time + 1;

      q.push({cur_pos * 2, cur_time + 1});
    }
  }
}

bool is_timeout(int time)
{
  if (time > Min_Time)
    return true;
  else
    return false;
}

bool is_target(int position)
{
  if (position == Target)
    return true;
  else
    return false;
}

bool can_visit(int position, int time)
{
  if (position <= MAX_LIMIT && position >= MIN_LIMIT && (!Visited[position] || Visited[position] >= time || position == Target))
    return true;
  else
    return false;
}

void update_result(int time)
{
  if (Min_Time > time)
  {
    Min_Time = time;
    Cnt = 1;
  }
  else if (Min_Time == time)
  {
    Cnt++;
  }
}
