#include <iostream>
#include <algorithm>

#define For(n,m) for(int i=n; i<m; i++)

using namespace std;

int k,n;
long long ans;
long long* line;
long long ideal;

void line_cut(long long left, long long right)
{
    int cnt = 0;
    long long mid = 0;
    while(left <= right)
    {
        cnt = 0;
        mid = (left+right)/2;
        
        For(0,k)
            cnt += line[i]/mid;
        if(cnt >= n)
        {
            ans = max(mid,ans);
            left = mid + 1;
        }
        else
            right = mid - 1;
        
    }
    printf("%lld\n",ans);
    
    
    
}

int main()
{
    scanf("%d %d",&k,&n);
    line = new long long[k];

    For(0,k)
    {
        scanf("%lld",&line[i]);
        ideal += line[i];
    }
    sort(line,line+k);

    ideal /= n;
    
    line_cut(1,line[k-1]);
}
