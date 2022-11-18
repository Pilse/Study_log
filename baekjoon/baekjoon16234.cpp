#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, l, r;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool bfs(vector<vector<int>> &g, vector<vector<int>> &visited, int i, int j);
bool can_visit(int cur, int next);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> l >> r;
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    
    bool can_move = true;
    int cnt = -1;
    
    while(can_move)
    {
        cnt++;
        can_move = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!visited[i][j])
                    can_move = bfs(g, visited, i, j) || can_move;
  
        for(auto &v : visited) fill(v.begin(), v.end(), 0);
    }
    cout << cnt << '\n';
}

bool bfs(vector<vector<int>> &g, vector<vector<int>> &visited, int i, int j)
{
    visited[i][j] = 1;
    int population = 0;
    int counties = 0;
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    q1.push({i, j});
    q2.push({i, j});
    
    while(!q1.empty())
    {
        auto &[cr, cc] = q1.front();
        q1.pop();
        population += g[cr][cc];
        counties++;
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nc < 0 || nc >= n || nr >= n || visited[nr][nc]) continue;
            if(can_visit(g[cr][cc], g[nr][nc]))
            {
                visited[nr][nc] = 1;
                q1.push({nr, nc});
                q2.push({nr, nc});
            }
            
        }
    }
    
    bool can_move = !(q2.size() == 1);
    while(!q2.empty())
    {
        auto &[cr, cc] = q2.front();
        q2.pop();
        g[cr][cc] = floor(population / counties);
    }
    return can_move;
}

bool can_visit(int cur, int next)
{
    int diff = abs(cur - next);
    if(diff < l) return false;
    if(diff > r) return false;
    return true;
}
