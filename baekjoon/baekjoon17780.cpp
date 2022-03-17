#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct pos
{
  int r;
  int c;
};

struct node
{
  int r;
  int c;
  int dir;
};

struct piece
{
  int num;
  int dir;
};

void input();
void chess();
void move_to_white(pos from, pos to);
void move_to_red(pos from, pos to);
void move_to_blue(pos from);
bool is_finished();

int N, K;
pair<int, deque<piece> > Map[14][14];
vector<node> Nodes;
int Dr[5] = {0, 0, 0, -1, 1};
int Dc[5] = {0, 1, -1, 0, 0};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  chess();
}

void input()
{
  cin >> N >> K;

  for (int i = 0; i <= N + 1; i++)
  {
    for (int j = 0; j <= N + 1; j++)
    {
      if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
      {
        Map[i][j].first = 2;
        continue;
      }

      cin >> Map[i][j].first;
    }
  }

  for (int i = 0; i < K; i++)
  {
    int r, c, dir;

    cin >> r >> c >> dir;

    Nodes.push_back({r, c, dir});
  }
}

void chess()
{
  int round = 0;

  for (int i = 0; i < (int)Nodes.size(); i++)
    Map[Nodes[i].r][Nodes[i].c].second.push_front({i, Nodes[i].dir});

  while (1)
  {
    if (is_finished())
    {
      cout << round << '\n';
      break;
    }

    if (round > 1000)
    {
      cout << -1 << '\n';
      break;
    }

    ++round;

    for (int i = 0; i < (int)Nodes.size(); i++)
    {
      int r = Nodes[i].r;
      int c = Nodes[i].c;
      int dir = Nodes[i].dir;

      if (Map[r][c].second.front().num != i)
        continue;

      if (Map[r + Dr[dir]][c + Dc[dir]].first == 0)
        move_to_white({r, c}, {r + Dr[dir], c + Dc[dir]});

      else if (Map[r + Dr[dir]][c + Dc[dir]].first == 1)
        move_to_red({r, c}, {r + Dr[dir], c + Dc[dir]});

      else if (Map[r + Dr[dir]][c + Dc[dir]].first == 2)
        move_to_blue({r, c});
    }
  }
}

void move_to_white(pos from, pos to)
{
  while (!Map[from.r][from.c].second.empty())
  {
    piece p = Map[from.r][from.c].second.front();

    Map[from.r][from.c].second.pop_front();

    Map[to.r][to.c].second.push_back(p);

    Nodes[p.num] = {to.r, to.c, p.dir};
  }
}

void move_to_red(pos from, pos to)
{
  while (!Map[from.r][from.c].second.empty())
  {
    piece p = Map[from.r][from.c].second.back();

    Map[from.r][from.c].second.pop_back();

    Map[to.r][to.c].second.push_back(p);

    Nodes[p.num] = {to.r, to.c, p.dir};
  }
}

void move_to_blue(pos from)
{
  piece p = Map[from.r][from.c].second.front();

  if (p.dir % 2 == 0)
    p.dir -= 1;
  else
    p.dir += 1;

  int dir = p.dir;

  Nodes[p.num] = {from.r, from.c, dir};
  Map[from.r][from.c].second.pop_front();
  Map[from.r][from.c].second.push_front({p.num, dir});

  if (Map[from.r + Dr[dir]][from.c + Dc[dir]].first == 2)
    return;

  else if (Map[from.r + Dr[dir]][from.c + Dc[dir]].first == 0)
    move_to_white(from, {from.r + Dr[dir], from.c + Dc[dir]});

  else if (Map[from.r + Dr[dir]][from.c + Dc[dir]].first == 1)
    move_to_red(from, {from.r + Dr[dir], from.c + Dc[dir]});
}

bool is_finished()
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (Map[i][j].second.size() >= 4)
        return true;
    }
  }

  return false;
}
