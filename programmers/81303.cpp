#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Node
{
  int idx;

  Node *prev;
  Node *next;

  Node(int _idx) : idx(_idx), prev(nullptr), next(nullptr) {}
};

string solution(int n, int k, vector<string> cmd)
{
  string answer(n, 'X');
  vector<Node *> v;
  stack<Node *> s;

  for (int i = 0; i < n; i++)
    v.push_back(new Node(i));

  v[0]->next = v[1];
  v[n - 1]->prev = v[n - 2];

  for (int i = 1; i < n - 1; i++)
  {
    v[i]->prev = v[i - 1];
    v[i]->next = v[i + 1];
  }

  Node *cur = v[k];

  for (int i = 0; i < cmd.size(); i++)
  {
    if (cmd[i][0] == 'U')
    {
      int num = stoi(cmd[i].substr(2));
      while (num--)
        cur = cur->prev;
    }
    else if (cmd[i][0] == 'D')
    {
      int num = stoi(cmd[i].substr(2));
      while (num--)
        cur = cur->next;
    }
    else if (cmd[i][0] == 'C')
    {
      s.push(cur);

      if (cur->prev == nullptr)
      {
        cur->next->prev = nullptr;
        cur = cur->next;
      }
      else if (cur->next == nullptr)
      {
        cur->prev->next = nullptr;
        cur = cur->prev;
      }
      else
      {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->next;
      }
    }
    else
    {
      Node *top = s.top();
      s.pop();

      if (top->prev != nullptr)
        top->prev->next = top;
      if (top->next != nullptr)
        top->next->prev = top;
    }
  }

  while (cur->prev != nullptr)
    cur = cur->prev;
  while (cur != nullptr)
  {
    answer[cur->idx] = 'O';
    cur = cur->next;
  }

  return answer;
}
