#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    string src;
    string t;
    char res[1000001];
    int idx = 0;
    
    cin >> src >> t;

    for(int i = 0; i < src.length(); i++)
    {
        res[idx++] = src[i];
        if(res[idx - 1] == t[t.length() - 1])
        {
            if(idx - t.length() >= 0)
            {
                for(int j = 0; j < t.length(); j++)
                {
                    if(res[idx - j - 1] != t[t.length() - j - 1])
                        break;
                    if(j == t.length() - 1)
                        idx -= t.length();
                }
            }
        }
    }
    
    if(!idx)
        cout << "FRULA" << '\n';
    else
    {
        for(int i = 0; i < idx; i++)
            cout << res[i];
    }

    
}
