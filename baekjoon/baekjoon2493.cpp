#include <iostream>
#include <queue>

using namespace std;

void input();
void tower();

int N, H;
deque<pair<int, int> > Dq;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();
  tower();
}

void input()
{
  cin >> N;
}

void tower()
{
  for (int i = 1; i <= N; i++)
  {
    cin >> H;

    if (Dq.empty())
    {
      cout << 0 << " ";
      Dq.push_back({H, i});
    }

    else if (Dq.front().first < H)
    {
      while (!Dq.empty() && Dq.front().first < H)
        Dq.pop_front();

      if (Dq.empty())
        cout << 0 << " ";

      else
        cout << Dq.front().second << " ";

      Dq.push_front({H, i});
    }

    else if (Dq.front().first >= H)
    {
      cout << Dq.front().second << " ";
      Dq.push_front({H, i});
    }
  }
}
