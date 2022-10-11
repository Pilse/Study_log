#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, s = 0;
  cin >> n;

  while (n--)
  {
    string command;
    int x;

    cin >> command;
    if (!(command == "all" || command == "empty"))
      cin >> x;

    if (command == "add")
    {
      s |= 1 << x;
      continue;
    }

    if (command == "remove")
    {
      s &= ~(1 << x);
      continue;
    }

    if (command == "toggle")
    {
      s ^= 1 << x;
      continue;
    }

    if (command == "all")
    {
      s = (1 << 21) - 1;
      continue;
    }

    if (command == "empty")
    {
      s = 0;
      continue;
    }

    bool checked = s & (1 << x);
    cout << checked << '\n';
  }
}
