#include <iostream>
#include <vector>
#include <string>

using namespace std;

void input();
void permute(int step, vector<int> nums);
pair<pair<int, int>, vector<int> > get_op_nums(int idx, vector<int> nums);
int calculate(int n1, int n2, char symbol);

int N, Result = -2147483647;
int Visited_Op[15];
int Visited_Num[15];
vector<int> Num;
vector<char> Op;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  input();

  permute(0, Num);

  cout << Result << '\n';
}

void input()
{
  cin >> N;

  string str;

  cin >> str;

  for (int i = 0; i < str.length(); i++)
  {
    if (i % 2 == 1)
      Op.push_back(str[i]);

    else
      Num.push_back(int(str[i]) - 48);
  }
}

void permute(int step, vector<int> nums)
{
  if (step == Op.size())
  {
    Result = max(Result, nums[0]);
  }

  for (int i = 0; i < Op.size(); i++)
  {
    if (!Visited_Op[i])
    {
      pair<pair<int, int>, vector<int> > targets = get_op_nums(i, nums);

      int calced = calculate(nums[targets.first.first], nums[targets.first.second], Op[i]);

      Visited_Op[i] = 1;
      Visited_Num[targets.first.second] = 1;
      targets.second[targets.first.first] = calced;
      permute(step + 1, targets.second);
      Visited_Op[i] = 0;
      Visited_Num[targets.first.second] = 0;
      targets.second[targets.first.first] = Num[targets.first.first];
    }
  }
}

pair<pair<int, int>, vector<int> > get_op_nums(int idx, vector<int> nums)
{
  int n1 = 0, n2 = 0;

  for (int i = idx; i >= 0; i--)
  {
    if (!Visited_Num[i])
    {
      n1 = i;
      break;
    }
  }

  for (int i = idx + 1; i < nums.size(); i++)
  {
    if (!Visited_Num[i])
    {
      n2 = i;
      break;
    }
  }

  return {{n1, n2}, nums};
}

int calculate(int n1, int n2, char symbol)
{
  switch (symbol)
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
