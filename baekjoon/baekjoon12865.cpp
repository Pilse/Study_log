#include <iostream>

using namespace std;

int w[110];
int v[110];
int dp[110][100010];

int main()
{
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=K;j++)
        {
            if(j-w[i]>=0)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    cout<<dp[N][K];

}
