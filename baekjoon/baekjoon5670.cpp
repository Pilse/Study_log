#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Trie{
    bool finish;
    int cnt = 0;
    Trie * nextNode[26];
    
    void insert(const char *key)
    {
        if(*key == '\0')
        {
            finish = true;
            return;
        }
        int index = *key - 'a';
        
        if(nextNode[index] == NULL)
        {
            nextNode[index] = new Trie();
            cnt ++;
        }
        
        nextNode[index]->insert(key + 1);
    }
    
    int find(const char *key, int num)
    {
        if(*key == '\0' && finish)
            return num;
        
        int index = *key - 'a';
        
        if (cnt == 1 && !finish)
            return nextNode[index]->find(key + 1, num);
        else
            return nextNode[index]->find(key + 1, num + 1);
            
    }
};

void free_all(struct Trie *cur)
{
  if(!cur)
    return;

  for(int i = 0; i < 26; i++)
  {
   free_all(cur->nextNode[i]);
  }
  delete(cur);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);
    
    int n;
    while(cin >> n)
    {
        int sum = 0;
        Trie* root = new Trie();

        string s;
        vector<string> str;

        for(int i = 0; i < n; i++)
        {
            cin >> s;
            str.push_back(s);
            root->insert(s.c_str());
        }
        for(int i = 0; i < n; i++)
        {
            sum += root->find(str[i].c_str(), 0);
        }
        if(root->cnt == 1)
            sum += n;
        
        cout <<  round((double)sum / n * 100) / 100 << '\n';
        
        free_all(root);

    }
    
}
