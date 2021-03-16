#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

ll* house;
ll result;

void share(int n,int c)
{
    ll left = 1;
    ll right = house[n-1] - house[0];
    while(left <= right)
    {
        int cnt = 1;
        
        ll mid = (right+left)/2;
        ll start = house[0];
        
        
        for(int i = 0; i < n; i++)
        {
            if(house[i] - start >= mid)
            {
                cnt++;
                start = house[i];
            }
        }
        
        if(cnt>=c)
        {
            result = max(result,mid);
            left = mid + 1;
        }
        else
            right = mid -1;
    }
    
}

int main()
{
    int n,c;
    scanf("%d %d",&n,&c);
    
    house = new ll[n];
    for(int i = 0; i < n; i++)
        scanf("%lld",&house[i]);
    
    sort(house,house+n);
    
    share(n,c);
    
    cout<<result<<endl;
}
