#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_same_pattern(string user_id, string banned_id)
{
  if (user_id.length() != banned_id.length())
    return false;

  for (int i = 0; i < banned_id.length(); i++)
  {
    if (banned_id[i] == '*')
      continue;

    if (banned_id[i] != user_id[i])
      return false;
  }

  return true;
}

int bfs(vector<int> banned_idx[9], int size)
{
  queue<pair<int, int> > q;
  int visited_arr[512]{0};
  int cnt = 0;

  for (int i = 0; i < banned_idx[0].size(); i++)
  {
    q.push({1, 1 << banned_idx[0][i]});
  }

  while (!q.empty())
  {
    int step = q.front().first;
    int visited = q.front().second;

    q.pop();

    if ((step == size) && !visited_arr[visited])
    {
      cnt++;
      visited_arr[visited] = 1;
      continue;
    }

    for (int i = 0; i < banned_idx[step].size(); i++)
    {
      int user_idx = banned_idx[step][i];

      if (!(visited & (1 << user_idx)))
      {
        q.push({step + 1, visited | (1 << user_idx)});
      }
    }
  }

  return cnt;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
  vector<int> banned_idx[9];

  for (int i = 0; i < banned_id.size(); i++)
  {
    for (int j = 0; j < user_id.size(); j++)
    {
      if (is_same_pattern(user_id[j], banned_id[i]))
      {
        banned_idx[i].push_back(j);
      }
    }
  }

  int answer = bfs(banned_idx, banned_id.size());
  return answer;
}