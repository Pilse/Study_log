#include <iostream>

using namespace std;

int M,N;
int flag;
int number[10];

void Print()
{
    for(int i=1;i<=M;i++)
    {
        cout<<number[i]<<" ";
    }
    cout<<endl;
}

void cal(int m)
{
    if(m>M)
        m=M;
    if(number[m]<N)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(i==number[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                continue;
            else
            {
                number[m]=i;
                if(m==M)
                    Print();
                flag=0;
                cal(m+1);
            }
        }
        
    }
    if(number[1]<N)
    {
        number[1] += 1;
        cal(2);
    }
    
}

int main()
{
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        number[i]=1;
    }
   
    cal(2);




}
