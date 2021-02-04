#include <iostream>

using namespace std;

int arr[1010];
int dp[1010];
int d[1010];


int main()
{
    int N;
    int index = 0;
    cin>> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];
  
    dp[0]=1;
    d[++index]=arr[0];
   
    for(int i=1;i<N;i++)
    {
        if(arr[i]>d[index])
        {
            dp[i]=++index;
            d[index]=arr[i];
        }
        if(arr[i]<d[index])
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

    cout<<index<<"\n";
    
}
