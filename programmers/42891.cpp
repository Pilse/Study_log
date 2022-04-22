#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> food_times, long long k)
{
  long long sum = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

  for (int i = 0; i < food_times.size(); i++)
  {
    pq.push({food_times[i], i + 1});
    sum += food_times[i];
  }
  if (sum <= k)
    return -1;

  int food_time = pq.top().first;
  int table_size = pq.size();
  long long prev_food_time = 0;
  while ((food_time - prev_food_time) * table_size <= k)
  {
    k -= (food_time - prev_food_time) * table_size;
    prev_food_time = food_time;
    pq.pop();

    food_time = pq.top().first;
    table_size = pq.size();
  }

  vector<pair<int, int> > remain_foods;
  while (!pq.empty())
  {
    int food_time = pq.top().first;
    int index = pq.top().second;
    remain_foods.push_back({index, food_time});
    pq.pop();
  }

  sort(remain_foods.begin(), remain_foods.end());

  int answer = remain_foods[k % remain_foods.size()].first;

  return answer;
}