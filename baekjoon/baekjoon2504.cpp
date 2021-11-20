#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    stack<int> st;
    
    cin >> str;
    
    int cntp = 0;
    int cnts = 0;
    
    string filtered;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
            cntp ++;
        if(str[i] == ')')
        {
            if(!cntp)
            {
                cout << 0 << '\n';
                return 0;
            }
            cntp --;
        }
        if(str[i] == '[')
            cnts ++;
        if(str[i] == ']')
        {
            if(!cnts)
            {
                cout << 0 << '\n';
                return 0;
            }
            cnts --;
        }
    }
    
    if(cntp || cnts) {
        cout << 0 << '\n';
        return 0;
    }
    
    int tot = 1;
    int res = 0;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            tot *= 2;
            st.push('(');
        }
        else if (str[i] == '[')
        {
            tot *= 3;
            st.push('[');
        }
        else if (str[i] == ')')
        {
            if(str[i - 1] == '(')
                res += tot;
            tot /= 2;
            st.pop();
        }
        else if (str[i] == ']')
        {
            if(str[i - 1] == '[')
                res += tot;
            tot /= 3;
            st.pop();
        }
    }
   
    
    cout << res << '\n';
}
