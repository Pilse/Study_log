#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
  string city;
  int size;
  Node *next;
  Node *prev;

  Node(string _city) : city(_city), size(0), next(nullptr), prev(nullptr) {}
};

string to_lower(string str)
{
  string lower = "";
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
      lower += char(str[i] + 32);
    }
    else
      lower += str[i];
  }
  return lower;
}

int solution(int cacheSize, vector<string> cities)
{
  Node *head = new Node("");
  head->prev = head;
  int size = 0, answer = 0;

  if (cacheSize == 0)
    return cities.size() * 5;

  for (int i = 0; i < cities.size(); i++)
  {
    string city = to_lower(cities[i]);

    bool cache_hit = false;

    for (auto iter = head->next; iter != nullptr; iter = iter->next)
    {
      if (iter->city == city)
      {
        if (iter->next != nullptr)
        {
          head->prev->next = iter;
          iter->prev->next = iter->next;
          iter->next->prev = iter->prev;
          iter->prev = head->prev;
          iter->next = nullptr;
          head->prev = iter;
        }
        answer++;
        cache_hit = true;
        break;
      }
    }

    if (!cache_hit)
    {
      Node *new_node = new Node(city);
      if (head->size == cacheSize)
      {
        head->prev->next = new_node;
        new_node->prev = head->prev;
        head->prev = new_node;

        Node *deleted = head->next;

        head->next = deleted->next;
        deleted->next->prev = head;

        free(deleted);
      }
      else
      {
        head->prev->next = new_node;
        new_node->prev = head->prev;
        head->prev = new_node;

        head->size++;
      }
      answer += 5;
    }
  }

  return answer;
}