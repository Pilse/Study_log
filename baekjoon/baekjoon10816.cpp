#include <iostream>
#include <algorithm>

#define For(n,m) for(int i=n;i<m;i++)

using namespace std;

int n,m;
int da[2][10000010];
int a[500010];
int b[500010];

void binary(int idx, int start, int end)
{
    int ref = b[idx];
    int cnt = 0;
    
    while(start <= end)
    {
        int mid = (start+end)/2;
      
        if(ref == a[mid])
        {
            if(ref >= 0)
                cnt = da[1][a[mid]];
            else
                cnt = da[0][abs(a[mid])];
        }
        if (ref > a[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    printf("%d ",cnt);
    
}


int main()
{
    cin>>n;
    For(0,n)
    {
        cin>>a[i];
        if(a[i]>=0)
            da[1][a[i]]++;
        else
            da[0][abs(a[i])]++;
    }
    cin>>m;
    For(0,m)
        cin>>b[i];

    sort(a,a+n);

    For(0,m)
        binary(i,0,n-1);
}
// #include <iostream>
// #include <algorithm>

// #define For(n,m) for(int i=n;i<m;i++)

// using namespace std;


// int main()
// {
//     int n,m;

//     int a[500010];
//     int b;
    
//     cin>>n;
//     For(0,n)
//         scanf("%d",&a[i]);
    
//     sort(a,a+n);
   
//     cin>>m;
//     For(0,m)
//     {
//         scanf("%d",&b);
//         printf("%ld ",upper_bound(a,a+n,b) - lower_bound(a,a+n,b));
//     }
    
// }