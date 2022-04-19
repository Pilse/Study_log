#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie
{
  bool finished;
  int number;
  Trie *Node[26];

  Trie()
  {
    finished = false;
    number = 0;
    for (int i = 0; i < 26; i++)
      Node[i] = nullptr;
  }

  void insert(char *key)
  {
    number++;

    if (*key == NULL)
    {
      finished = true;
      return;
    }

    char c = *key;

    if (Node[c - 'a'] == nullptr)
    {
      Node[c - 'a'] = new Trie();
    }

    Node[c - 'a']->insert(key + 1);
  }

  void find(char *key, int &cnt)
  {
    if (*key == NULL)
      return;
    if (number == 1)
      return;

    char c = *key;
    Node[c - 'a']->find(key + 1, ++cnt);
  }
};

int solution(vector<string> words)
{
  int answer = 0;
  Trie *root = new Trie();

  for (int i = 0; i < words.size(); i++)
  {
    string word = words[i];

    vector<char> v(word.begin(), word.end());
    v.push_back('\0');

    char *key = &v[0];

    root->insert(key);
  }

  for (int i = 0; i < words.size(); i++)
  {
    string word = words[i];

    vector<char> v(word.begin(), word.end());
    v.push_back('\0');

    char *key = &v[0];

    int cnt = 0;

    root->find(key, cnt);

    answer += cnt;
  }

  return answer;
}