#include <iostream>
#include <vector>

using namespace std;

int M,N;
int visited[10];
vector<int> a;

void Print()
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}


void cal(int cnt, int m)
{
    if(cnt==M+1)
    {
        Print();
        return;
    }
    else
    {
        for(int i=m;i<=N;i++)
        {
            if(visited[i])
                continue;
            visited[i]=1;
            a.push_back(i);
            cal(cnt+1,i);
            a.pop_back();
            visited[i]=0;
        }
    }
}

int main()
{
    cin>>N>>M;
    
   
    cal(1, 1);
}
