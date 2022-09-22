#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<string> split(string str, string delimeter)
{
  vector<string> vec;

  int pos = 0;
  while ((pos = str.find(delimeter)) != -1)
  {
    vec.push_back(str.substr(0, pos));
    str = str.substr(pos + delimeter.length());
  }
  if (!str.empty())
    vec.push_back(str);

  return vec;
}

int to_num(string str)
{
  vector<string> time_vec = split(str, ":");
  return stoi(time_vec[0]) * 3600 + stoi(time_vec[1]) * 60 + stoi(time_vec[2]);
}

string to_time(int n)
{
  int d = n / 3600;
  string h = d < 10 ? "0" + to_string(d) : to_string(d);
  n %= 3600;
  d = n / 60;
  string m = d < 10 ? "0" + to_string(d) : to_string(d);
  n %= 60;
  string s = n < 10 ? "0" + to_string(n) : to_string(n);

  return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
  int pt = to_num(play_time);
  int at = to_num(adv_time);

  vector<long long> viewers(pt + 2, 0);

  for (auto &log : logs)
  {
    vector<string> times = split(log, "-");
    viewers[to_num(times[0])]++;
    viewers[to_num(times[1])]--;
  }

  long long viewer_cnt = viewers[0];
  for (int i = 1; i < viewers.size(); i++)
  {
    viewer_cnt += viewers[i];
    viewers[i] = viewers[i - 1] + viewer_cnt;
  }

  long long max_time = viewers[at];
  int answer = 0;
  for (int i = 1; i < pt - at + 1; i++)
  {
    if (viewers[i + at - 1] - viewers[i - 1] > max_time)
    {
      max_time = viewers[i + at - 1] - viewers[i - 1];
      answer = i;
    }
  }

  return (to_time(answer));
}
