#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int top = -1;
int stack[100000];

void push(int num)
{
    stack[++top] = num;
}

int pop()
{
    int temp = stack[top--];
    return temp;
}


int main()
{
    int K = 0;
    int n = 0;
    int result = 0;

    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &n);
        if (n == 0)
            pop();
        else
            push(n);
    }
    for (int i = top; i >= 0; i--)
    {
        result = result + pop();
    }
    printf("%d", result);

}
