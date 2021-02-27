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


void cal(int cnt)
{
    if(cnt==M+1)
    {
        Print();
        return;
    }
    else
    {
        for(int i=1;i<=N;i++)
        {  
            visited[i]=1;
            a.push_back(i);
            cal(cnt+1);
            a.pop_back();
           
        }
    }
}

int main()
{
    cin>>N>>M;
    
   
    cal(1);
}
