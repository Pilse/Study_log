#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int t=0;
int N,K;

void bfs()
{
    int pos = 0;

    while(!q.empty())
    {
        pos = q.front().first;
        t=q.front().second;
        q.pop();

        if(pos-1>=0)
            q.push({pos-1,t-1});
        if(pos+1<=N)
            q.push({pos+1,t+1});
        if(pos*2<=N)
            q.push({pos*2,t*2});
        if(pos==K)
            break;
    }
}

int main()
{

    cin>>N>>K;
    q.push({N,0});

    bfs();
    
    cout<<t<<endl;

}