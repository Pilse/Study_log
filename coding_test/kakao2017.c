#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* arr1 = malloc(sizeof(int) * n);
    int* arr2 = malloc(sizeof(int) * n);
    int* arr3 = malloc(sizeof(int) * n);
    int* arr4 = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);

    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);

    }
    for (int i = 0; i < n; i++)
    {
        arr3[i] = (arr1[i] | arr2[i]);

    }
    for (int x = 0; x < n; x++)
    {
        for (int i = n-1; i >= 0; i--)
        {
            if (i)
            {
                arr4[i] = arr3[x] % 2;
                arr3[x] = arr3[x] / 2;
            }
            if (!i)
                arr4[i] = arr3[x];

        }
        for (int i = 0; i < n; i++)
        {
            if (arr4[i])
                printf("#");
            if (!arr4[i])
                printf(" ");
        }
        printf("\n");

    }
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    return 0;
}