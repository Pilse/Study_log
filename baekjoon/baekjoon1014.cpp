#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dp[15][1025];

bool isAdjacent(int bit, int x)
{
  for (int i = 0; i < x - 1; i++)
  {
    int val = 3 << i;
    if ((bit & val) == val)
      return false;
  }
  return true;
}

bool isBroken(string str, int bit)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == 'x' && (bit & (1 << i)))
      return false;
  }
  return true;
}

bool isPossibleSeat(int ba, int fr, int x)
{
  for (int i = 0; i < x; i++)
  {
    if (fr & (1 << i))
    {
      if (i > 0 && (ba & (1 << (i - 1))))
        return false;
      if (ba & (1 << (i + 1)))
        return false;
    }
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;

  while (tc--)
  {
    int y, x;
    int tot = 0;
    string str[15];
    cin >> y >> x;

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= y; i++)
      cin >> str[i];

    vector<pair<int, int> > bits;
    for (int bit = 0; bit < 1 << x; bit++)
    {
      if (isAdjacent(bit, x))
      {
        int cnt = 0;
        for (int i = 0; i < x; i++)
        {
          if (1 << i & bit)
            cnt++;
          bits.push_back({bit, cnt});
        }
      }
    }
    for (int i = 1; i <= y; i++)
    {
      for (pair<int, int> bbit : bits)
      {
        if (!isBroken(str[i], bbit.first))
          continue;
        for (pair<int, int> fbit : bits)
        {
          if (isPossibleSeat(bbit.first, fbit.first, x))
          {
            dp[i][bbit.first] = max(dp[i][bbit.first], dp[i - 1][fbit.first] + bbit.second);
            tot = max(tot, dp[i][bbit.first]);
          }
        }
      }
    }
    cout << tot << '\n';
  }
}
