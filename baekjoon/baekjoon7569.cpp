#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[100][100][100];
int visited[100][100][100];
int cnt;

int M,N,H;
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1};

queue<pair<tuple<int,int,int>,int>> q;

void bfs()
{
    while(!q.empty())
    {
        pair<tuple<int,int,int>,int> p=q.front();
        q.pop();
        for(int i=0;i<6;i++)
        {
            int z =get<0>(p.first)+dz[i];
            int y =get<1>(p.first)+dy[i];
            int x =get<2>(p.first)+dx[i];
            if(z<0 || z>H || y<0 || y>N || x<0 ||x>M)
                continue;
            if(map[z][y][x]==1 && !visited[z][y][x])
            {
                visited[z][y][x]=1;
                q.push({{z,y,x},cnt+1});
            }
        }
    }
}



int main()
{
    cin>>M>>N>>H;
    for(int z=0;z<H;z++)
    {
        for(int y=0;y<N;y++)
        {
            for(int x=0;x<M;x++)
            {
                cin>>map[z][y][x];
                if(map[z][y][x]==1)
                {
                    q.push({{z,y,x},0});
                    visited[z][y][x]=1;
                }
            }
        }
    }

    bfs();
    cout<<cnt;

}