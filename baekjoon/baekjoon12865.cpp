#include <iostream>

using namespace std;

pair<int,int> things[110];
pair<int,int> dp[110];

int main ()
{
    int n,k;
    int temp1,temp2;
    int idx=0;
    int largest=0;
    cin>>n>>k;

    for(int i=0;i<n;i++)
    {
        cin>>temp1>>temp2;
        things[i]=(make_pair(temp1,temp2));
    }
    for(int i=0;i<n;i++)
    {
        if(things[i].first>k)
            continue;
        for(int j=0;j<idx;i++)
        {
            if(dp[j].first+things[i].first>k)
                continue;
            dp[j].first=dp[j].first+things[i].first;
            dp[j].second=dp[j].second+things[j].second;
        }
        dp[++idx].first=things[i].first;  
        dp[idx].second=things[i].second;
    }
    for(int i=0;i<idx;i++)
    {
        largest=max(largest,dp[i].second);
    }
    cout<<largest<<endl;
    
}