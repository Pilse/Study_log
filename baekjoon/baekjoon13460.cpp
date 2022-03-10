#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node
{
  int r;
  int c;
};

struct map
{
  char map[11][11];
};

void input();
void bfs();
bool is_red_more_to_left(node r, node b, map map);
bool is_red_more_to_top(node r, node b, map map);
node move_node(int direction, node n, map map);
map update_map(char color, node from, node to, map map);

int R, C;
node Red, Blue, Goal;
map M;
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  bfs();
}

void input()
{
  cin >> R >> C;

  for (int i = 0; i < R; i++)
  {
    string str;

    cin >> str;

    for (int j = 0; j < C; j++)
    {
      if (str[j] == 'R')
        Red = {i, j};
      else if (str[j] == 'B')
        Blue = {i, j};
      else if (str[j] == 'O')
        Goal = {i, j};

      M.map[i][j] = str[j];
    }
  }
}

void bfs()
{
  queue<pair<pair<pair<node, node>, int>, map> > q;

  q.push({{{Red, Blue}, 0}, M});

  while (!q.empty())
  {
    node cur_red = q.front().first.first.first;
    node cur_blue = q.front().first.first.second;
    int round = q.front().first.second;
    map cur_map = q.front().second;

    q.pop();

    if (round > 10)
      continue;

    if (cur_blue.r == Goal.r && cur_blue.c == Goal.c)
      continue;

    if (cur_red.r == Goal.r && cur_red.c == Goal.c)
    {
      cout << round << '\n';
      return;
    }

    for (int i = 0; i < 4; i++)
    {
      node next_red = cur_red;
      node next_blue = cur_blue;
      map next_map = cur_map;

      switch (i)
      {
      case 0:
        if (is_red_more_to_top(cur_red, cur_blue, next_map))
        {
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
        }
        else
        {
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
        }
        break;

      case 1:
        if (is_red_more_to_left(cur_red, cur_blue, next_map))
        {
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
        }
        else
        {
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
        }
        break;

      case 2:
        if (is_red_more_to_top(cur_red, cur_blue, next_map))
        {
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
        }
        else
        {
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
        }
        break;

      case 3:
        if (is_red_more_to_left(cur_red, cur_blue, next_map))
        {
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
        }
        else
        {
          next_blue = move_node(i, cur_blue, next_map);
          next_map = update_map('B', cur_blue, next_blue, next_map);
          next_red = move_node(i, cur_red, next_map);
          next_map = update_map('R', cur_red, next_red, next_map);
        }
        break;

      default:
        break;
      }

      if (round + 1 <= 10)
        q.push({{{next_red, next_blue}, round + 1}, next_map});
    }
  }

  cout << -1 << '\n';
}

bool is_red_more_to_left(node r, node b, map map)
{
  return r.c < b.c;
}

bool is_red_more_to_top(node r, node b, map map)
{
  return r.r < b.r;
}

node move_node(int direction, node n, map map)
{
  int moved_r = n.r;
  int moved_c = n.c;

  switch (direction)
  {
  case 0:
    while (moved_r > 1 && map.map[moved_r - 1][moved_c] == '.')
      moved_r--;

    if (map.map[moved_r - 1][moved_c] == 'O')
      moved_r--;

    break;

  case 1:
    while (moved_c < C - 1 && map.map[moved_r][moved_c + 1] == '.')
      moved_c++;

    if (map.map[moved_r][moved_c + 1] == 'O')
      moved_c++;

    break;

  case 2:
    while (moved_r < R - 1 && map.map[moved_r + 1][moved_c] == '.')
      moved_r++;

    if (map.map[moved_r + 1][moved_c] == 'O')
      moved_r++;

    break;

  case 3:
    while (moved_c > 1 && map.map[moved_r][moved_c - 1] == '.')
      moved_c--;

    if (map.map[moved_r][moved_c - 1] == 'O')
      moved_c--;

    break;

  default:
    break;
  }

  return {moved_r, moved_c};
}

map update_map(char color, node from, node to, map map)
{
  map.map[from.r][from.c] = '.';
  map.map[to.r][to.c] = color;

  map.map[Goal.r][Goal.c] = 'O';

  return map;
}
