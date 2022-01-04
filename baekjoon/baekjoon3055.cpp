#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct coor {
    int r;
    int c;
};

void input();
void water_bfs();
void starter_bfs();

coor S, D;
int R, C;
int Map[51][51];
int Visited[51][51];
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0 , -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    water_bfs();
    starter_bfs();
}

void input()
{
    cin >> R >> C;
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            char temp;
            cin >> temp;
            
            if(temp == 'S')
            {
                S = {i, j};
                Map[i][j] = -1;
            }
            else if(temp == 'D')
            {
                D = {i, j};
                Map[i][j] = -2;
            }
            else if(temp == 'X')
            {
                Map[i][j] = -3;
            }
            else if(temp == '.')
            {
                Map[i][j] = -4;
            }
            else if(temp == '*')
            {
                Map[i][j] = 0;
            }
        }
    }
}

void water_bfs()
{
    queue<pair<coor, int>> q;
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(Map[i][j] == 0)
                q.push({{i, j}, 0});
        }
    }
    
    while(!q.empty())
    {
        int cr = q.front().first.r;
        int cc = q.front().first.c;
        int ctime = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + Dr[i];
            int nc = cc + Dc[i];
            
            if(nr < 0 || nc < 0 || nr >= R || nc >= C || Map[nr][nc] != -4) continue;
            
            Map[nr][nc] = ctime + 1;
            
            q.push({{nr, nc}, ctime + 1});
        }
    }
    
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(Map[i][j] == -4)
                Map[i][j] = 2501;
        }
    }
}

void starter_bfs()
{
    Visited[S.r][S.c] = 1;
    
    queue<pair<coor, int>> q;
    
    q.push({S, 0});
    
    while(!q.empty())
    {
        int cr = q.front().first.r;
        int cc = q.front().first.c;
        int ctime = q.front().second;
        
//        cout << cr << " " << cc << '\n';
        
        q.pop();
        
        if(Map[cr][cc] == -2)
        {
            cout << ctime << '\n';
            return;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + Dr[i];
            int nc = cc + Dc[i];
            
            if(nr < 0 || nc < 0 || nr >= R || nc >= C || Visited[nr][nc] || Map[nr][nc] == -3) continue;
            
            if(Map[nr][nc] == -2 || Map[nr][nc] > ctime + 1)
            {
                Visited[nr][nc] = 1;
                q.push({{nr, nc}, ctime + 1});
            }
        }
    }
    
    cout << "KAKTUS" << '\n';
}
