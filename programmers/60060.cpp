#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie
{
  int finish;
  int children;
  Trie *nodes[26];

  Trie() : finish(0), children(0)
  {
    for (int i = 0; i < 26; i++)
      nodes[i] = nullptr;
  }

  void insert(char *key)
  {
    if (*key == NULL)
    {
      finish++;
      return;
    }

    children++;
    int idx = *key - 'a';

    if (nodes[idx] == nullptr)
      nodes[idx] = new Trie();

    nodes[idx]->insert(key + 1);
  }

  int find(char *key)
  {
    if (*key == NULL)
      return finish;

    char c = *key;

    if (c == '?')
      return children;

    int idx = c - 'a';

    if (nodes[idx] == nullptr)
      return 0;

    return nodes[idx]->find(key + 1);
  }
};

vector<int> solution(vector<string> words, vector<string> queries)
{
  vector<int> answer;
  Trie *t1[10001]{nullptr};
  Trie *t2[10001]{nullptr};

  for (int i = 0; i < words.size(); i++)
  {
    string word = words[i];
    int len = word.length();
    char *key = word.data();

    if (t1[len] == nullptr)
      t1[len] = new Trie();
    t1[len]->insert(key);

    reverse(word.begin(), word.end());
    key = word.data();

    if (t2[len] == nullptr)
      t2[len] = new Trie();
    t2[len]->insert(key);
  }

  for (int i = 0; i < queries.size(); i++)
  {
    string query = queries[i];
    int len = query.length();

    if (query[0] == '?')
    {
      reverse(query.begin(), query.end());
      char *key = query.data();
      if (t2[len] == nullptr)
        answer.push_back(0);
      else
        answer.push_back(t2[len]->find(key));
    }
    else
    {
      char *key = query.data();
      if (t1[len] == nullptr)
        answer.push_back(0);
      else
        answer.push_back(t1[len]->find(key));
    }
  }

  return answer;
}