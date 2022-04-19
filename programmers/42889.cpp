#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, double> &a, pair<int, double> &b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
  vector<pair<int, int> > players(N + 2);
  vector<pair<int, double> > failure;
  vector<int> answer;

  for (int i = 0; i < stages.size(); i++)
  {
    for (int j = 1; j < stages[i]; j++)
    {
      int nu = players[j].first;
      int de = players[j].second;
      players[j] = {nu, de + 1};
    }

    int nu = players[stages[i]].first;
    int de = players[stages[i]].second;
    players[stages[i]] = {nu + 1, de + 1};
  }

  for (int i = 1; i < players.size() - 1; i++)
  {
    if (players[i].second == 0)
      failure.push_back({i, 0});
    else
    {
      double ratio = (double)players[i].first / players[i].second;
      failure.push_back({i, ratio});
    }
  }

  sort(failure.begin(), failure.end(), compare);

  for (int i = 0; i < failure.size(); i++)
    answer.push_back(failure[i].first);

  return answer;
}