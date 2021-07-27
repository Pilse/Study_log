#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    for(int i = 0; i < n / 2; i++)
    {
        if(str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

bool isAllSameLetter(string str)
{
    int n = str.length();
    int c = str[0];
    
    for(int i = 1 ; i < n; i++)
    {
        if(str[i] != c)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str;
    
    cin >> str;
    
    if(isPalindrome(str))
    {
        if(isAllSameLetter(str))
        {
            cout << -1 << '\n';
        }
        else
            cout << str.length() - 1 << '\n';
    }
    else
    {
        cout << str.length() << '\n';;
    }
    
}
