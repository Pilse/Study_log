#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vec[10];

void init()
{
    vec[0].push_back("#####");
    vec[0].push_back("#...#");
    vec[0].push_back("#####");
    
    vec[1].push_back("#####");
    
    vec[2].push_back("#.###");
    vec[2].push_back("#.#.#");
    vec[2].push_back("###.#");
    
    vec[3].push_back("#.#.#");
    vec[3].push_back("#.#.#");
    vec[3].push_back("#####");
    
    vec[4].push_back("###..");
    vec[4].push_back("..#..");
    vec[4].push_back("#####");
    
    vec[5].push_back("###.#");
    vec[5].push_back("#.#.#");
    vec[5].push_back("#.###");
    
    vec[6].push_back("#####");
    vec[6].push_back("#.#.#");
    vec[6].push_back("#.###");
    
    vec[7].push_back("#....");
    vec[7].push_back("#....");
    vec[7].push_back("#####");
    
    vec[8].push_back("#####");
    vec[8].push_back("#.#.#");
    vec[8].push_back("#####");
    
    vec[9].push_back("###.#");
    vec[9].push_back("#.#.#");
    vec[9].push_back("#####");
}

int find_num(string* sig, int i)
{
    int numbers[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    for(int n = 0; n <= 9; n++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(n == 1)
                continue;
            
            if(sig[i + j].compare(vec[n][j]))
            {
                numbers[n] = 0;
                break;
            }
        }
    }
    
    for(int n = 0; n <= 9; n++)
    {
        if(numbers[n] && n != 1)
            return n;
    }
    
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, signal_num;
    string str;
    
    cin >> n;
    cin >> str;
    
    int col = n / 5;
    
    string sig[col];
    
    for(int i = 0; i < n; i = i + col)
    {
        string substr = str.substr(i, col);
        
        for(int j = 0; j < col; j++)
            sig[j] += substr[j];
    }
    
    init();
    
    for(int i = 0; i < col;)
    {
        if(sig[i].find('#') >= sig[i].length())
        {
            i += 1;
            continue;
        }
        
        if(i + 2 > col)
        {
            cout << 1;
            break;
        }
        
        signal_num = find_num(sig, i);
        
        if(signal_num == 1)
        {
            cout << 1;
            i += 1;
        }
        else
        {
            cout << signal_num;
            i += 3;
        }
    }
}
