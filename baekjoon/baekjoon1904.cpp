#include <iostream>
#define MOD 15746
using namespace std;

unsigned long long dp[1000001] = { 0, };

unsigned long long makeTile(int n)
{
    if (n == 1)
    {
        return dp[1];
    }
    if (n == 2)
    {
        return dp[2];
    }
    if (n > 1)
    {
        if (dp[n] != 0)
        {
            return dp[n];
        }
        else
        {
            dp[n] = (makeTile(n - 1)%MOD + makeTile(n - 2)%MOD)%MOD;
            return dp[n];
        }
    }
    
}

int main()
{
    int N;
    cin >> N;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    unsigned long long result = makeTile(N);
    cout << result;
}