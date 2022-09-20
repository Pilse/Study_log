#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool is_not_avaliable_char(char &c)
{
  if (isalpha(c))
    return false;
  if (isdigit(c))
    return false;

  vector<char> vec{'-', '_', '.'};

  return find(vec.begin(), vec.end(), c) == vec.end();
}

string solution(string new_id)
{
  // step 1
  transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

  // step 2
  new_id.erase(remove_if(new_id.begin(), new_id.end(), ::is_not_avaliable_char), new_id.end());

  // step 3
  int start = 0;
  while ((start = new_id.find("..", start)) != -1)
    new_id.replace(start, 2, ".");

  // step 4
  if (new_id.front() == '.')
    new_id.erase(new_id.begin());
  if (new_id.back() == '.')
    new_id.pop_back();

  // step 5
  if (new_id.empty())
    new_id += "a";

  // step 6
  if (new_id.length() >= 16)
    new_id.erase(15);
  if (new_id.back() == '.')
    new_id.pop_back();

  // step 7
  while (new_id.length() <= 2)
    new_id += new_id.back();

  return new_id;
}