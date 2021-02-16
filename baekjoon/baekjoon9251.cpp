#include <iostream>
#include <string>
using namespace std;



int dp[1010];
int pre[1010];

int main()
{
    string str1;
    string str2;
    
    int cnt;
    
    cin>>str1;
    cin>>str2;
    
    for(int i=0;i<str2.length();i++)
    {
        for(int j=0;j<str1.length();j++)
        {
            if(str1[j]==str2[i])
            {
                cnt=pre[j-1];
                
                for(int k=j;k<str1.length();k++)
                {
                    if(dp[k]>=cnt+1)
                        continue;
                    dp[k]=cnt+1;
                }
            }
        }
        for(int j=0;j<str1.length();j++)
        {
            pre[j]=dp[j];
        }

    }
    cout<<dp[str1.length()-1];
    
}
