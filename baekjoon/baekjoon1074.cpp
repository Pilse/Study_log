#include <iostream>
#include <cmath>

using namespace std;

void input();
void get_sequence(int r, int c, int n, int sequence);
int get_location(int r, int c, int n);
pair<int, int> get_updated_position(int location, int length, int r, int c);

int N, R, C;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  get_sequence(R, C, N, 0);
}

void input()
{
  cin >> N >> R >> C;
}

void get_sequence(int r, int c, int n, int sequence)
{
  if (n == 0)
  {
    cout << sequence << '\n';
    return;
  }

  int length = (int)pow(2, n);

  int location = get_location(r, c, n);

  int current_sequence = sequence + (location - 1) * (length * length / 4);

  pair<int, int> updated_position = get_updated_position(location, length, r, c);

  get_sequence(updated_position.first, updated_position.second, n - 1, current_sequence);
}

int get_location(int r, int c, int n)
{
  int length = (int)pow(2, n);

  int location = 1;

  if (c >= length / 2)
    location++;

  if (r >= length / 2)
    location += 2;

  return location;
}

pair<int, int> get_updated_position(int location, int length, int r, int c)
{
  switch (location)
  {
  case 1:
    return {r, c};
  case 2:
    return {r, c - length / 2};
  case 3:
    return {r - length / 2, c};
  case 4:
    return {r - length / 2, c - length / 2};
  default:
    return {r, c};
  }
}
