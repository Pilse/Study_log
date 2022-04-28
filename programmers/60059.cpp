#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > rotate_key(vector<vector<int> > key)
{
  int n = key.size();
  vector<vector<int> > rotated(n, vector<int>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      rotated[j][n - i - 1] = key[i][j];
    }
  }

  return rotated;
}

vector<vector<int> > expand_key(vector<vector<int> > key, int s)
{
  int n = key.size();
  vector<vector<int> > expanded(n + 2 * (s - 1), vector<int>(n + 2 * (s - 1), 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      expanded[i + s - 1][j + s - 1] = key[i][j];
    }
  }

  return expanded;
}

bool check(vector<vector<int> > key, vector<vector<int> > lock, int i, int j)
{
  int l = lock.size();

  for (int r = i; r < i + l; r++)
  {
    for (int c = j; c < j + l; c++)
    {
      if (!(key[r][c] ^ lock[r - i][c - j]))
        return false;
    }
  }

  return true;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock)
{
  vector<vector<int> > expanded = expand_key(key, max(key.size(), lock.size()));
  int k = expanded.size();
  int l = lock.size();

  for (int n = 0; n < 4; n++)
  {
    for (int i = 0; i <= k - l; i++)
    {
      for (int j = 0; j <= k - l; j++)
      {
        if (check(expanded, lock, i, j))
          return true;
      }
    }
    expanded = rotate_key(expanded);
  }

  return false;
}