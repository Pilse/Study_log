#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct info
{
  string time;
  string car_id;
  string status;
};

int to_minute(string str)
{
  return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records)
{
  vector<int> answer;
  vector<info> infos;
  unordered_map<string, int> m;
  map<string, int> result;

  for (auto &record : records)
  {
    string time, car_id, status;

    istringstream iss(record);
    iss >> time >> car_id >> status;

    infos.push_back({time, car_id, status});
  }

  sort(infos.begin(), infos.end(), [](info &v1, info &v2)
       { return v1.time < v2.time; });

  for (auto &info : infos)
  {
    if (info.status == "IN")
    {
      m[info.car_id] = to_minute(info.time);
      continue;
    }

    result[info.car_id] += to_minute(info.time) - m[info.car_id];
    m[info.car_id] = -1;
  }

  for (auto &car : m)
    if (car.second != -1)
      result[car.first] += to_minute("23:59") - car.second;

  for (auto &r : result)
  {
    int fee = fees[1];
    int ex = r.second - fees[0];

    if (ex > 0)
      fee += ceil((double)ex / fees[2]) * fees[3];

    answer.push_back(fee);
  }

  return answer;
}