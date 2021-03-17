#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;


ll result;

void calc(ll n, ll k)
{
    ll left = 1;
    ll right = k;
    
    while(left<=right)
    {
        ll mid = (left+right) / 2;
        int cnt = 0;
        
        for(int i = 1;i<=n;i++)
            cnt += min(mid/i,n);
        
        if(cnt >= k)
        {
            result = mid;
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
