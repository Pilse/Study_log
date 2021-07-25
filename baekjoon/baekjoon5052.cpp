#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Trie{
    bool finish;
    Trie * nextNode[11];
    
    void insert(char * key)
    {
        if(*key == '\0')
        {
            finish = true;
        }
        else
        {
            int index = *key - '0';
            if(nextNode[index] == NULL)
            {
                nextNode[index] = new Trie();
            }
            nextNode[index]->insert(key + 1);
        }
    }
    
    bool find(char * key)
    {
        if(*key == '\0')
            return true;
        if(finish)
            return false;
        
        int index = *key - '0';
        return nextNode[index]->find(key + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc --)
    {
        int n;
        int endFlag = 0;
        cin >> n;
        
        Trie * root = new Trie();
        char str[n][11];
        
        for(int i = 0; i < n; i++)
        {
            cin >> str[i];
            
            root->insert(str[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!(root->find(str[i])))
            {
                cout << "NO" << '\n';
                endFlag = 1;
                break;
            }
        }
        if(!endFlag)
            cout << "YES" << '\n';
        
        
    }
    
}
