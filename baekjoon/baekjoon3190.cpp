// 매초마다 정보 업데이트
// 게임이 끝났는지 확인
// 메인게임
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coor
{
  int r;
  int c;
};

void input();
void snake_game();
bool is_finished();
void update_position();

int N, K, L, Time;
int Direction = 1;
int Map[101][101];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};
coor Head, Tail;
vector<pair<int, char> > Instruction;
queue<coor> Tail_move;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  snake_game();

  cout << Time + 1 << '\n';
}

void input()
{
  cin >> N >> K;

  for (int i = 0; i < K; i++)
  {
    int r, c;

    cin >> r >> c;

    Map[r - 1][c - 1] = 9;
  }

  cin >> L;

  for (int i = 0; i < L; i++)
  {
    int t;
    char d;

    cin >> t >> d;

    Instruction.push_back({t, d});
  }
}

void snake_game()
{
  int instruction_idx = 0;
  int next_instruction_time = Instruction[instruction_idx].first;
  char next_instruction_dir = Instruction[instruction_idx].second;

  Head = {0, 0};
  Tail = {0, 0};

  Map[Head.r][Head.c] = 1;

  while (1)
  {
    if (Time == next_instruction_time)
    {
      if (next_instruction_dir == 'D')
        Direction = (Direction + 1) % 4;
      else
        Direction = Direction - 1 < 0 ? 3 : Direction - 1;

      if (instruction_idx < L - 1)
      {
        next_instruction_time = Instruction[++instruction_idx].first;
        next_instruction_dir = Instruction[instruction_idx].second;
      }
    }

    if (is_finished())
      break;

    update_position();

    Time++;
  }
}

bool is_finished()
{
  int nr = Head.r + Dr[Direction];
  int nc = Head.c + Dc[Direction];

  if (nr < 0 || nc < 0 || nr >= N || nc >= N)
    return true;

  if (Map[nr][nc] == 1)
    return true;

  return false;
}

void update_position()
{
  int nr = Head.r + Dr[Direction];
  int nc = Head.c + Dc[Direction];
  bool is_apple = true;

  Head = {nr, nc};

  if (Map[nr][nc] != 9)
    is_apple = false;

  Tail_move.push({Dr[Direction], Dc[Direction]});

  Map[Head.r][Head.c] = 1;

  if (!is_apple)
  {
    Map[Tail.r][Tail.c] = 0;

    if (!Tail_move.empty())
    {
      Tail = {Tail.r + Tail_move.front().r, Tail.c + Tail_move.front().c};

      Tail_move.pop();
    }
    else
      Tail = Head;
  }
}
