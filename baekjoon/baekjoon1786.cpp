#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string s)
{
    int length = s.length();
    int j = 0;
    vector<int> v(length, 0);
    for(int i = 1; i < length; i++)
    {
        while(j > 0 && s[i] != s[j])
            j = v[j - 1];
        if(s[i] == s[j])
            v[i] = ++j;
    }
    return v;
}

vector<int> kmp(string t, string p)
{
    int t_length = t.length();
    int p_length = p.length();
    vector<int> pi = getPi(p);
    vector<int> arr;
    int j = 0;

    for(int i = 0; i < t_length; i++)
    {
        while(j > 0 && t[i] != p[j])
        {
            j = pi[j - 1];
        }
        if(t[i] == p[j])
        {
            if(j == p_length - 1)
            {
                arr.push_back(i - p_length + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return arr;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string t, p;

    getline(cin, t);
    getline(cin, p);

    vector<int> result = kmp(t, p);
    cout << result.size() << '\n';

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] + 1 << " ";
    }



}
