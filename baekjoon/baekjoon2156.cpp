#include <iostream>

using namespace std;

int dt[10010];
int dp[10010];

//xoo
//oxo
//oox
//xox

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<n+1;i++)
    {
        cin>>dt[i];
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(i==1)
            dp[i]=dt[i];
        if(i==2)
            dp[i]=dt[i]+dt[i-1];
        else
        {
            dp[i]=dp[i-2]+dt[i];
            dp[i]=max(dp[i],dp[i-1]);
            dp[i]=max(dp[i],(dp[i-3]+dt[i-1]+dt[i]));
        }
    }
    cout<<dp[n]<<"\n";
}
