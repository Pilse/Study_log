#include <iostream>
#include <vector>

using namespace std;

vector<int> population;
vector<int> visited;
vector<vector<int>> map;
vector<vector<int>> dp;

int find_town(int cur, int type);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;
  population.resize(n + 1);
  map.resize(n + 1);
  visited.resize(n + 1, 0);
  dp.resize(n + 1, vector<int>(2, -1));

  for (int i = 1; i <= n; i++)
    cin >> population[i];
  for (int i = 0; i < n - 1; i++)
  {
    int n1, n2;
    cin >> n1 >> n2;
    map[n1].push_back(n2);
    map[n2].push_back(n1);
  }

  cout << max(find_town(1, 0), find_town(1, 1));
}

int find_town(int cur, int type)
{
  if (dp[cur][type] != -1)
    return dp[cur][type];
  dp[cur][type] = type ? population[cur] : 0;
  visited[cur] = 1;
  for (auto n : map[cur])
  {
    if (visited[n])
      continue;
    dp[cur][type] += !type ? max(find_town(n, type ^ 1), find_town(n, type)) : find_town(n, type ^ 1);
  }
  visited[cur] = 0;
  return dp[cur][type];
}
