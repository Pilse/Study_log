#include <iostream>
using namespace std;

int dp[101];

int wave (int n)
{
    if(!dp[n])
        return dp[n];
    else
    {
        dp[n]=wave(n-2)+wave(n-3);
        return dp[n];
    }
}

int main()
{
    dp[0]=dp[1]=dp[2]=1;
    int N;
    cin >> N;
    cout << wave(N);
}