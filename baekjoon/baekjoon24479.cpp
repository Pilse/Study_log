#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, r;
  int idx = 1;

  cin >> n >> m >> r;

  vector<vector<int>> vec(n + 1);
  vector<int> visited(n + 1, 0);
  stack<int> st;

  for (int i = 0; i < m; i++)
  {
    int n1, n2;
    cin >> n1 >> n2;

    vec[n1].push_back(n2);
    vec[n2].push_back(n1);
  }

  for (int i = 1; i <= n; i++)
    sort(vec[i].begin(), vec[i].end(), greater<int>());

  st.push(r);
  while (!st.empty())
  {
    int cur = st.top();
    st.pop();

    if (visited[cur])
      continue;
    visited[cur] = idx++;

    for (int i = 0; i < vec[cur].size(); i++)
    {
      if (!visited[vec[cur][i]])
        st.push(vec[cur][i]);
    }
  }

  for (int i = 1; i <= n; i++)
    cout << visited[i] << '\n';
}
