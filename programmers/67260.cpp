#include <string>
#include <vector>
#include <deque>
#include <map>

using namespace std;

map<int, int> Key;
int Visited[200001];
vector<int> Edge[200001];

bool check_all_room(int n)
{
  deque<int> dq;

  if (Visited[0] == -1)
    return false;

  Visited[0] = 1;

  dq.push_front(0);

  while (!dq.empty())
  {
    int cur = dq.front();

    dq.pop_front();

    if (Visited[cur] == -2)
      return false;

    if (!Visited[cur])
      Visited[cur] = 1;

    auto precede = Key.find(cur);

    if (precede != Key.end())
    {
      if (Visited[precede->second] == -2)
      {
        dq.push_front(precede->second);
      }
      Visited[precede->second] = 0;
    }

    for (int i = 0; i < Edge[cur].size(); i++)
    {
      int next = Edge[cur][i];

      if (Visited[next] == 1)
        continue;

      if (Visited[next] == -1)
      {
        Visited[next] = -2;
        dq.push_back(next);
      }
      else if (Visited[next] == 0)
      {
        Visited[next] = 1;
        dq.push_front(next);
      }
    }
  }

  return true;
}

bool solution(int n, vector<vector<int> > path, vector<vector<int> > order)
{
  for (int i = 0; i < path.size(); i++)
  {
    Edge[path[i][0]].push_back(path[i][1]);
    Edge[path[i][1]].push_back(path[i][0]);
  }

  for (int i = 0; i < order.size(); i++)
  {
    Key[order[i][0]] = order[i][1];
    Visited[order[i][1]] = -1;
  }

  bool answer = check_all_room(n);
  return answer;
}