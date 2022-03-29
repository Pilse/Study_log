#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> allocated_room;

long long find_room(long long room)
{
  auto result = allocated_room.find(room);

  if (result == allocated_room.end())
  {
    allocated_room.insert({room, room + 1});
    return room;
  }
  else
  {
    return allocated_room[room] = find_room(result->second);
  }
}

vector<long long> solution(long long k, vector<long long> room_number)
{
  vector<long long> answer;

  for (int i = 0; i < room_number.size(); i++)
  {
    long long room_found = find_room(room_number[i]);

    answer.push_back(room_found);
  }

  return answer;
}