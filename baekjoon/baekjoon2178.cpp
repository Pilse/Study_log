#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> vec[105][105];
queue<pair<int,int>> q;
int shortest;
int visited[105][105];
int cnt[105][105];


void bfs(pair<int,int>start,int n,int m)
{
    q.push({start.first,start.second});
    visited[start.first][start.second]=1;
    cnt[start.first][start.second]=1;
    while(!q.empty())
    {
        pair<int,int> p =q.front();
        q.pop();
        if(p.first==n && p.second==m)
        {
            shortest=cnt[n][m];
        }

        for(int i=0;i<vec[p.first][p.second].size();i++)
        {
            pair<int,int> w = vec[p.first][p.second][i];
            if(!visited[w.first][w.second])
            {
                cnt[w.first][w.second]=cnt[p.first][p.second]+1;
                visited[w.first][w.second]=1;
                q.push(w);
            }
        }
    }

}

int main()
{
    char map[105][105];
    int N,M;
    cin>>N>>M;
    for(int i=1;i<N+1;i++)
    {
        scanf("%s",map[i]+1);
    }
    
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<M+1;j++)
        {
            if(map[i][j]=='1')
            {
                if(map[i][j-1]=='1')
                {
                    vec[i][j].push_back({i,j-1});
                    vec[i][j-1].push_back({i,j});
                }
                if(map[i][j+1]=='1')
                {
                    vec[i][j].push_back({i,j+1});
                    vec[i][j+1].push_back({i,j});
                }
                if(map[i-1][j]=='1')
                {
                    vec[i-1][j].push_back({i,j});
                    vec[i][j].push_back({i-1,j});
                }
                 if(map[i+1][j]=='1')
                {
                    vec[i+1][j].push_back({i,j});
                    vec[i][j].push_back({i+1,j});
                }
            }

        }
    }
    bfs({1,1},N,M);
    cout<<shortest;



}
