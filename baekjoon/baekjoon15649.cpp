#include <iostream>

using namespace std;

int M,N;
int flag;
int a[10];

void Print()
{
    for(int i=1;i<=M;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}


void cal(int m)
{
    if(m>M)
        m=M;
    for(int i=1;i<=N;i++)
    {
        if(m==1)
        {
            a[m]=i;
            if(m!=M)
                cal(m+1);
            else
                Print();
        }
        else
        {
            for(int j=1;j<m;j++)
            {
                if(i==a[j])
                    break;
                if(j==m-1)
                {
                    a[m]=i;
                    if(m!=M)
                        cal(m+1);
                    else
                        Print();
                }
            }
        }
    }
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        a[i]=1;
    }
   
    cal(1);
}
