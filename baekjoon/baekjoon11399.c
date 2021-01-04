#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    int temp = 0;
    int result = 0;
    int* minute = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &minute[i]);
    }

   /* for (int i = 0; i < N - 1; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (minute[i] > minute[j])
            {
                temp = minute[i];
                minute[i] = minute[j];
                minute[j] = temp;
            }
        }
    }
    */
    qsort(minute,N,sizeof(minute[0]),compare);
    for (int i = 0; i < N; i++)
    {
        result = result + (N - i) * minute[i];
        printf("%d\n", minute[i]);

    }

    printf("%d", result);
    
    
}