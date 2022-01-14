#include <iostream>
#include <algorithm>

using namespace std;

void input();
int calc();

int N, Max;
int Arr[9];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    sort(&Arr[0], &Arr[N - 1]);
    
    do
    {
        Max = max(calc(), Max);
        
    } while(next_permutation(&Arr[0], &Arr[N]));
    
    cout << Max << '\n';;
    
}

void input()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> Arr[i];
}

int calc()
{
    int sum = 0;
    
    for(int i = 0; i < N - 1; i++)
        sum += abs(Arr[i] - Arr[i + 1]);
    
    return sum;
}
