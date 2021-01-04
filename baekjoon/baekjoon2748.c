#include<stdio.h>

long long fibo(long long n, long long prev, long long next)
{
     if (n == 1)
        return next;
    else
     fibo(n - 1, next,prev+next);
}
int main()
{
   
    int n = 0;
    scanf("%d", &n);
     long long result = fibo(n,0,1);
    printf("%lld", result);
}