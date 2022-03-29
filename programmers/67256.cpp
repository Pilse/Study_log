#include <string>
#include <vector>

using namespace std;

struct node
{
  int x;
  int y;
};

node get_transformed(int n)
{
  node pos;

  if (n == 0)
  {
    pos.x = 4;
    pos.y = 2;
  }
  else if (n % 3 == 0)
  {
    pos.x = n / 3;
    pos.y = 3;
  }
  else
  {
    pos.x = n / 3 + 1;
    pos.y = n % 3;
  }

  return pos;
}

int get_distance(node a, node b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

string solution(vector<int> numbers, string hand)
{
  string answer = "";
  node left_hand = {4, 1};
  node right_hand = {4, 3};

  for (int i = 0; i < numbers.size(); i++)
  {
    node transformed = get_transformed(numbers[i]);
    int left_distance = get_distance(left_hand, transformed);
    int right_distance = get_distance(right_hand, transformed);

    if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
    {
      answer += 'L';
      left_hand = transformed;
    }

    else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
    {
      answer += 'R';
      right_hand = transformed;
    }

    else if (left_distance == right_distance)
    {
      if (hand == "right")
      {
        answer += 'R';
        right_hand = transformed;
      }
      else
      {
        answer += 'L';
        left_hand = transformed;
      }
    }

    else if (left_distance < right_distance)
    {
      answer += 'L';
      left_hand = transformed;
    }

    else
    {
      answer += 'R';
      right_hand = transformed;
    }
  }

  return answer;
}
