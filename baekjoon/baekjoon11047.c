#include <stdio.h>

int main()
{
    int N=0;
    int K=0;
    scanf("%d %d",&N,&K);

    int* number = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&number[N-i-1]);
    }
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        if(number[i]<K)
        {
        cnt = K/number[i];
        K=K%number[i];
        }
    }
    printf("%d",cnt);
    free(number);
    return 0;

}