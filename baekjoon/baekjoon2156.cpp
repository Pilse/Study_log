#include <iostream>
#include <string.h>

using namespace std;

int amount[10100];
int dp[10100];
int dp1,dp2;
//xoo 1
//oxo 2
//oox 3
//xox 4



int maximum(int n,int recent)
{
    if(dp[n])
    {
        if(recent==1 || recent==2)
            return dp[n];
        else
            return 0;
    }
    else
    {
        if(recent==1)
        {
            dp[n]=maximum(n-1,2)+amount[n];
        }
        if(recent==2)
        {
            dp2=maximum(n-1,3)+amount[n];
            dp1=maximum(n-1,4)+amount[n];
            dp[n]=max(dp1,dp2);
        }
        if(recent==3)
        {
            dp[n]=maximum(n-1,1);
        }
        if(recent==4)
        {
            dp[n]=maximum(n-1,2);
        }
    }
    return dp[n];
    
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1 ; i < N + 1 ; i ++)
    {
        cin>>amount[i];
    }
    dp[1]=amount[1];

    int result1 = maximum(N,1);
    memset(dp,0,sizeof(dp));
    dp[1]=amount[1];
    int result2 = maximum(N,2);
    memset(dp,0,sizeof(dp));
    dp[1]=amount[1];
    int result3 = maximum(N,3);
    memset(dp,0,sizeof(dp));
    dp[1]=amount[1];
    int result4 = maximum(N,4);
    
    cout<<result1<<" "<<result2<<" "<<result3<<" "<<result4<<endl;
    int result = max({result1,result2,result3});
    cout<<result;

}

