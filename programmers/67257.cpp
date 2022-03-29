#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool is_operand(char c)
{
  return (c == '+' || c == '-' || c == '*');
}

bool is_new_operand(char c, vector<char> operands_used)
{
  for (int i = 0; i < operands_used.size(); i++)
  {
    if (c == operands_used[i])
      return false;
  }

  return true;
}

pair<int, int> get_target_numbers(int idx, int *number_visited, vector<long long> numbers)
{
  int n1_idx = idx;
  int n2_idx = idx + 1;

  for (int i = n1_idx; i >= 0; i--)
  {
    n1_idx = i;
    if (!number_visited[i])
      break;
  }

  for (int i = n2_idx; i < numbers.size(); i++)
  {
    n2_idx = i;
    if (!number_visited[i])
    {
      number_visited[i] = 1;
      break;
    }
  }

  return {n1_idx, n2_idx};
}

long long calculate(char operand, long long n1, long long n2)
{
  switch (operand)
  {
  case '+':
    return n1 + n2;
  case '-':
    return n1 - n2;
  case '*':
    return n1 * n2;
  default:
    return n1 + n2;
  }
}

long long permutation(vector<long long> numbers, vector<char> operands, vector<char> operands_used, int number_visited[101], int operand_visited[4], int step)
{
  long long max_num = 0;
  if (step == operands_used.size())
  {
    return abs(numbers[0]);
  }

  for (int i = 0; i < operands_used.size(); i++)
  {
    if (!operand_visited[i])
    {
      operand_visited[i] = 1;
      char operand = operands_used[i];

      vector<long long> numbers_copied(numbers.size());
      int number_visited_copied[101];
      copy(numbers.begin(), numbers.end(), numbers_copied.begin());
      copy(number_visited, number_visited + 100, number_visited_copied);

      for (int j = 0; j < operands.size(); j++)
      {
        if (operands[j] == operand)
        {
          pair<int, int> targets = get_target_numbers(j, number_visited_copied, numbers_copied);

          long long calculated = calculate(operands[j], numbers_copied[targets.first], numbers_copied[targets.second]);

          numbers_copied[targets.first] = calculated;
        }
      }

      max_num = max(max_num, permutation(numbers_copied, operands, operands_used, number_visited_copied, operand_visited, step + 1));
      operand_visited[i] = 0;
    }
  }

  return max_num;
}

long long get_max_num(vector<long long> numbers, vector<char> operands, vector<char> operands_used)
{
  int number_visited[101]{0};
  int operand_visited[4]{0};

  long long max_num = permutation(numbers, operands, operands_used, number_visited, operand_visited, 0);

  return max_num;
}

long long solution(string expression)
{
  long long answer = 0;
  string temp_num = "";
  vector<long long> numbers;
  vector<char> operands;
  vector<char> operands_used;

  for (int i = 0; i < expression.length(); i++)
  {
    char c = expression[i];

    if (is_operand(c))
    {
      operands.push_back(c);
      if (is_new_operand(c, operands_used))
      {
        operands_used.push_back(c);
      }
    }

    else
    {
      temp_num += c;

      if (i + 1 == expression.length() || is_operand(expression[i + 1]))
      {
        numbers.push_back((long long)stoi(temp_num));
        temp_num = "";
      }
      else
        continue;
    }
  }
  answer = get_max_num(numbers, operands, operands_used);

  return answer;
}