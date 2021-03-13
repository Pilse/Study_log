#include <iostream>
#include <algorithm>

#define For(n,m) for(int i=n;i<m;i++)

using namespace std;

int n,m;
int a[100010];
int b[100010];

void binary(int idx, int start, int end)
{
    int ref = b[idx];
    
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(ref == a[mid])
        {
            printf("1\n");
            return;
        }
        else if (ref > a[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    printf("0\n");
    
}


int main()
{
    cin>>n;
    For(0,n)
        cin>>a[i];

    cin>>m;
    For(0,m)
        cin>>b[i];

    sort(a,a+n);

    For(0,m)
        binary(i,0,n);
}
