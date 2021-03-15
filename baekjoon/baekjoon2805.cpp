#include <iostream>
#include <algorithm>

#define For(n,m) for(int i = n ; i < m ; i++ )
#define ll long long

using namespace std;

ll* tree;
int n, m;

void cut()
{
    ll left = 1;
    ll right = tree[n - 1];

    ll tot = 0;
    ll result = 0;

    while(left <= right)
    {
        tot = 0;
        
        ll mid = (left+right) / 2;
        For(0,n)
        {
            if(tree[i] - mid < 0)
                continue;
            tot += tree[i] - mid;
        }
        if (tot >= m)
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    printf("%lld\n",result);
}

int main()
{
    cin >> n >> m;

    tree = new ll[n];
    
    For(0,n)
        scanf("%lld",&tree[i]);
    
    sort(tree, tree + n);
    
    cut();
}
