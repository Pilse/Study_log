#include <stdio.h>

#define pi 3.141593
int main()
{
    int R = 0;
    double result1 = 0;
    double result2 = 0;
    scanf("%d", &R);

    result1 = pi * R * R;
    result2 = (double)2 * R;
    printf("%lf\n%lf\n", result1, result2);

    return 0;
}