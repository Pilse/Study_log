#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void input();
void hanoi(int n, int start, int to, int via);
void move(int start, int to);
string hanoi_cnt(int n);

int N;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  cout << hanoi_cnt(N) << '\n';

  if (N <= 20)
    hanoi(N, 1, 3, 2);
}

void input()
{
  cin >> N;
}

void move(int start, int to)
{
  cout << start << " " << to << '\n';
}

void hanoi(int n, int start, int to, int via)
{
  if (n == 1)
    move(start, to);

  else
  {
    hanoi(n - 1, start, via, to);

    move(start, to);

    hanoi(n - 1, via, to, start);
  }
}

string hanoi_cnt(int n)
{
  string cnt_string = to_string(pow(2, n));

  int idx = (int)cnt_string.find('.');

  cnt_string = cnt_string.substr(0, idx);

  cnt_string[cnt_string.length() - 1] -= 1;

  return cnt_string;
}
