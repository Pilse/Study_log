#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
string ns[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int nn[] = {1, 4 ,5 ,9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

int rome_to_num(string str)
{
    int idx = 0;
    int tot = 0;
    
    while(idx <= str.length())
    {
        auto item = m.find(str.substr(idx, 2));
        
        if(item == m.end())
        {
            tot += m[str.substr(idx, 1)];
            idx += 1;
        }
        else
        {
            tot += item -> second;
            idx += 2;
        }
    }
    
    return tot;
}

string num_to_rome(int num)
{
    string res;
    int div;
    
    for(int i = 0; i < 13; i++)
    {
        div = num / nn[12 - i];
        
        for(int j = 0; j < div; j++)
            res += ns[12 - i];
        
        num = num % nn[12 - i];
    }
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str1, str2;
    
    for(int i = 0; i < 13; i++)
        m[ns[i]] = nn[i];
    
    cin >> str1 >> str2;
    
    int sum_num = rome_to_num(str1) + rome_to_num(str2);
    
    string sum_str = num_to_rome(sum_num);
    
    cout << sum_num << '\n';
    cout << sum_str << '\n';
}
