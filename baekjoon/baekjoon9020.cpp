#include <iostream>

using namespace std;

void init();
void input();
bool goldbach(int n, int m);

int Tc, Target;
int Arr[10001];
int Ans1, Ans2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
    input();
    
    while(Tc --)
    {
        cin >> Target;
        
        for(int i = 2; i <= Target / 2; i++)
        {
           if(goldbach(i, Target - i))
           {
               Ans1 = i;
               Ans2 = Target - i;
           }
        }
        
        cout << Ans1 << " " << Ans2 << '\n';
    }
}

void init()
{
    for(int i = 2; i < 10001; i++)
        for(int j = i * 2; j < 10001; j = j + i)
            Arr[j] = 1;
}

void input()
{
    cin >> Tc;
}

bool goldbach(int n, int m)
{
    if(!Arr[n] && !Arr[m])
        return true;
    
    return false;
}
