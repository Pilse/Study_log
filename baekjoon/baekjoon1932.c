#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N = 0;
    int result=0;
    scanf("%d", &N);
    int** tri = malloc(sizeof(int) * (N+1));
    int** dp = malloc(sizeof(int) * (N+1));

    for (int i = 0; i < N+1; i++)
    {
        tri[i] = malloc(sizeof(int) * (N+1));
        dp[i] = malloc(sizeof(int) * (N+1));
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d", &tri[i][j]);
            dp[i][j] = 0;

        }
    }

    dp[0][0] = tri[0][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + tri[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
            }
            else {
                if ((dp[i - 1][j - 1] + tri[i][j]) > (dp[i - 1][j] + tri[i][j]))
                    dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
                else
                    dp[i][j] = dp[i - 1][j] + tri[i][j];
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        if (dp[N - 1][i] > result)
            result = dp[N - 1][i];
    }
    printf("%d", result);

    for (int i = 0; i < N+1; i++)
    {
        free(tri[i]);
        free(dp[i]);
    }
    free(tri);
    free(dp);
    return 0;
}