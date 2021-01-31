#include <iostream>

#define div 1000000000

using namespace std;
//[number][step]
int dp[110][110];

int stairs(int number, int step)
{
    if (dp[number][step])
        return dp[number][step];
    else
    {
        if (number == 0)
            dp[number][step] = stairs(number + 1, step - 1) % div;
        else if (number == 9)
            dp[number][step] = stairs(number - 1, step - 1) % div;
        else
        {
            dp[number][step] = (stairs(number - 1, step - 1) % div + stairs(number + 1, step - 1) % div) % div;
        }
    }
}

int main()
{
    int result;

    int N;
    cin >> N;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0 || i == 9)
            dp[i][1] = 1;
        else
            dp[i][1] = 2;
    }
    for (int i = 1; i < 10; i++)
    {
        result = (result % div + stairs(i, N) % div) % div;
    }
    printf("%d",result);
}