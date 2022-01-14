#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

void input();
void bfs();
void decay_cheese();
void reset();
void print_map();

int R, C, Time;
int Map[101][101];
int Map2[101][101];
int Visited[101][101];
int Dr[4] = { -1, 0, 1, 0 };
int Dc[4] = { 0, 1, 0, -1};
bool Active = true;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    while(Active)
    {
        Time ++;
        Active = false;
        
        bfs();
        decay_cheese();
        reset();
    }
    
    cout << Time << '\n';

}

void input()
{
    cin >> R >> C;
    
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> Map[i][j];
}

void bfs()
{
    Visited[0][0] = 1;
    
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    
    while(!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + Dr[i];
            int nc = cc + Dc[i];
            
            if(nr < 0 || nc < 0 || nr >= R || nc >= C || Visited[nr][nc] || Map[nr][nc] == 1) continue;
            
            Visited[nr][nc] = 1;
            
            Map[nr][nc] = 2;
            q.push({nr, nc});
        }
    }
}

void decay_cheese()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(Map[i][j] == 1)
            {
                Map2[i][j] = 1;
                
                int cnt = 0;
                
                for(int k = 0; k < 4; k++)
                {
                    int nr = i + Dr[k];
                    int nc = j + Dc[k];
                    
                    if(nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                    
                    if(Map[nr][nc] == 2) cnt++;
                }
                
                if(cnt >= 2) Map2[i][j] = 0;
                else Active = true;
            }
        }
    }
}

void reset()
{
    copy(&Map2[0][0], &Map2[100][100], &Map[0][0]);
    memset(Visited, 0, sizeof(Visited));
    memset(Map2, 0, sizeof(Map2));
}
