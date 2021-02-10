#include <iostream>
#include <string.h>

using namespace std;

int largest_index;
int dp[1010];

int lis(int *arr,int N)
{
    if(N==0)
        return 0;
    int d[1010];
    int index=0;

    dp[0]=1;
    d[++index]=arr[0];

     for(int i=1;i<N;i++)
    {
        if(arr[i]==d[index])
            largest_index=i;
        if(arr[i]>d[index])
        {
            largest_index=i;
            dp[i]=++index;
            d[index]=arr[i];
        }
        else if(arr[i]<=d[index])
        {
            for(int j=1;j<=index;j++)
            {
                if(d[j]>=arr[i])
                {
                    d[j]=arr[i];
                    dp[i]=dp[j-1];
                    break;
                }
            }
        }
    }
    return index;
}

int main()
{
    int N;
    int arr[1010];
    int revarr[1010];
    int indexf=0;
    int indexl=0;
    int temp[1010];

    cin>> N;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        revarr[N-i-1]=arr[i];
    }
    lis(arr,N);
    for(int i = 0 ; i < N ; i++)
    {
        temp[i]=dp[i];
    }
    for(int i = 0 ; i < N ; i++)
    {
        indexf=max(indexf,lis(revarr,N-i)+temp[i]-1);
    }

    memset(dp,0,sizeof(dp));

    lis(revarr,N);
    for(int i = 0 ; i < N ; i++)
    {
        temp[i]=dp[i];
    }
    for(int i = 0 ; i < N ; i++)
    {
        indexl=max(indexl,lis(arr,N-i)+temp[i]-1);
    }
    cout<<max(indexf,indexl)<<endl;
    
}
