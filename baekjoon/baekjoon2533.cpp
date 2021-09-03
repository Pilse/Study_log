#include <iostream>
#include <vector>

using namespace std;

int visited[1000001];
int dp[1000001][2];
vector<int> tree[1000001];
vector<int> graph[1000001];

void treeToGraph(int s)
{
  visited[s] = 1;

  for (int i = 0; i < tree[s].size(); i++)
  {
    int next = tree[s][i];
    if (!visited[next])
    {
      graph[s].push_back(next);
      treeToGraph(next);
    }
  }
}

int findAdapter(int s, int t)
{
  if (dp[s][t] != -1)
    return dp[s][t];
  if (t)
  {
    dp[s][t] = 1;
    for (int i = 0; i < graph[s].size(); i++)
    {
      int next = graph[s][i];
      dp[s][t] += min(findAdapter(next, 0), findAdapter(next, 1));
    }
  }
  else
  {
    dp[s][t] = 0;
    for (int i = 0; i < graph[s].size(); i++)
    {
      int next = graph[s][i];
      dp[s][t] += findAdapter(next, 1);
    }
  }
  //    cout <<s<<" "<<t<<" "<<dp[s][t]<<'\n';
  return dp[s][t];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a, b;
  cin >> n;

  for (int i = 1; i < n; i++)
  {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  dp[n][0] = -1;
  dp[n][1] = -1;

  treeToGraph(1);
  cout << min(findAdapter(1, 0), findAdapter(1, 1));
}
