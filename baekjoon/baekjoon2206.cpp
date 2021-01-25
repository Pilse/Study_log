#include <iostream>
#include <queue>

using namespace std;

//{{x,y},{cnt,wall}}
queue<pair<pair<int,int>,pair<int,int>>> q;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int visited[1010][1010];
char map[1010][1010];
int N,M;
int wall;
int cnt;
int flag;

void bfs()
{
    q.push({{0,0},{1,0}});
    visited[0][0]=1;
    while(!q.empty())
    {
        pair<pair<int,int>,pair<int,int>> p = q.front();
        cnt=p.second.first;
        wall=p.second.second;
        q.pop();
        
        if(p.first.first==(N-1) && p.first.second==(M-1))
        {
            flag=1;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int y = p.first.first+dy[i];
            int x = p.first.second+dx[i];
            if(y<0 || y>=N || x<0 || x>=M)
                continue;
            if(!visited[y][x] && map[y][x]=='0'&& wall==0)
            {
                visited[y][x]=1;
                q.push({{y,x},{cnt+1,0}});
            }
            else if(!visited[y][x] && map[y][x]=='0'&& wall==1)
            {
                visited[y][x]=1;
                q.push({{y,x},{cnt+1,1}});
            }
            else if(!visited[y][x] && map[y][x]=='1'&& wall==0)
            {
                visited[y][x]=1;
                q.push({{y,x},{cnt+1,1}});
            }
        }
    }

}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>map[i];
    }

    bfs();

    if(!flag)
        cout<<-1<<endl;
    else
        cout<<cnt<<endl;

    return 0;
}
