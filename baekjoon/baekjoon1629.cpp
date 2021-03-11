#include <iostream>

using namespace std;

long long mul(long a, long b,long c)
{
    if(b==1)
        return a%c;
    else
    {
        if(b%2 == 0)
            return mul(((a%c)*(a%c))%c,b/2,c);
        else
            return ((a%c) * mul(((a%c)*(a%c))%c,(b-1)/2,c))%c;
    }
}

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    
    long long result = mul(a,b,c);
    
    cout<< result << endl;
}
