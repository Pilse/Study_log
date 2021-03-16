#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;


ll result;

void calc(ll n, ll k)
{
    ll left = 1;
    ll right = k;
    int flag = 0;
    
    while(left<=right)
    {
        ll mid = (left+right) / 2;
        int cnt = 0;
        
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(mid >= i*j)
                    cnt++;
                if(cnt >= k)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        if(cnt >= k)
        {
            result = max(result,mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
}

int main()
{
    ll n,k;

    scanf("%lld %lld",&n,&k);

    
    calc(n, k);
    
    cout<<result<<endl;

}
