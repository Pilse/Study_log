#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct dp
{
    int zero;
    int one;
}dynamicp;

dynamicp dp[41];

dynamicp plus(dynamicp A, dynamicp B)
{
    dynamicp temp;
    temp.zero = A.zero + B.zero;
    temp.one = A.one + B.one;
    return temp;
}

dynamicp fibo(int n)
{
    if (n == 0)
        return dp[0];
    if (n == 1)
        return dp[1];
    if (dp[n].one != 0 || dp[n].zero != 0)
        return dp[n];
    else
        return dp[n] = plus(fibo(n - 1), fibo(n - 2));

}

int main()
{
    int n = 0;
    int i = 0;
    dp[0].zero = 1; dp[0].one = 0;
    dp[1].zero = 0; dp[1].one = 1;

    scanf("%d", &i);
    for (int x = 0; x < i; x++)
    {
        scanf("%d", &n);
        fibo(n);
        printf("%d %d\n", dp[n].zero, dp[n].one);
    }


}

