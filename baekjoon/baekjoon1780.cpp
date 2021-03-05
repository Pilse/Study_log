#include <iostream>

using namespace std;

int N;
int paper[2200][2200];
int m1;
int zero;
int p1;

void divide(int y,int x, int size)
{
    int std = paper[y][x];
    int flag = 0;

    for(int i=y; i<y+size; i++)
    {
        for(int j=x; j<x+size; j++)
        {
            if(std != paper[i][j])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }

    if(flag)
    {
        divide(y,x,size/3);
        divide(y+size/3,x,size/3);
        divide(y,x+size/3,size/3);
        divide(y+size/3,x+size/3,size/3);
        divide(y+2*size/3,x,size/3);
        divide(y,x+2*size/3,size/3);
        divide(y+2*size/3,x+2*size/3,size/3);
        divide(y+2*size/3,x+size/3,size/3);
        divide(y+size/3,x+2*size/3,size/3);
    }
    else
    {
        if(std==1)
            p1++;
        else if(std==0)
            zero++;
        else
            m1++;
    }
    
}

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>paper[i][j];
        }
    }

    divide(0,0,N);
    cout<<m1<<endl<<zero<<endl<<p1<<endl;
}
