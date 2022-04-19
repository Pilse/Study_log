#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> split(string str, char delimeter)
{
  vector<string> v;
  string temp = "";

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == delimeter)
    {
      v.push_back(temp);
      temp = "";
    }
    else
    {
      temp += str[i];
    }
  }
  v.push_back(temp);

  return v;
}

vector<string> solution(vector<string> record)
{
  vector<string> answer;
  vector<pair<string, string> > uid_status;
  map<string, string> users;

  for (int i = 0; i < record.size(); i++)
  {
    vector<string> splited = split(record[i], ' ');

    string status = splited[0];
    string uid = splited[1];

    if (status != "Change")
      uid_status.push_back({status, uid});

    if (status != "Leave")
    {
      string nickname = splited[2];
      users[uid] = nickname;
    }
  }

  for (int i = 0; i < uid_status.size(); i++)
  {
    string status = uid_status[i].first;
    string uid = uid_status[i].second;
    string message = "";

    if (status == "Enter")
      message = users[uid] + "님이 들어왔습니다.";
    else
      message = users[uid] + "님이 나갔습니다.";

    answer.push_back(message);
  }

  return answer;
}