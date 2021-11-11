#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    string hr;
    int cnt = 0;
    
    for(int i = 0; i < 80; i++)
        hr += "-";
    
    while(cin >> str)
    {
        if(str == "<br>")
        {
            cout << '\n';
            cnt = 0;
            continue;
        }
        
        if(str == "<hr>")
        {
            if(cnt == 0)
                cout << hr << '\n';
            else
                cout << '\n' << hr << '\n';
            cnt = 0;
            continue;
        }
        
        if(str == "\n")
            continue;
        
        if(cnt + str.length() >= 80)
        {
            cout << '\n';
            cnt = 0;
        }
        else if(cnt != 0)
        {
            cout << " ";
            cnt += 1;
        }
        
        cout << str;
        cnt += (int)str.length();
    }
    
    cout << '\n';
}
