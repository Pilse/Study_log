#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void bfs(vector<string> &v, vector<vector<int>> &visited, int r, int c, bool disabled);
bool is_same_color(char color1, char color2, bool disabled);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    
    vector<string> vec(n);
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    for(auto &v : vec) cin >> v;
    
    int cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                cnt1++;
                bfs(vec, visited, i, j, 0);
            }
        }
    }
    
    int cnt2 = 0;
    for(auto &v : visited) fill(v.begin(), v.end(), 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                cnt2++;
                bfs(vec, visited, i, j, 1);
            }
        }
    }
    
    cout << cnt1 << " " << cnt2 << '\n';
}

void bfs(vector<string> &v, vector<vector<int>> &visited, int r, int c, bool disabled)
{
    int length = (int)v.size();
    char target_color = v[r][c];
    visited[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    
    while(!q.empty())
    {
        auto &[cr, cc] = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr < 0 || nc < 0 || nr >= length || nc >= length || visited[nr][nc]) continue;
            if(is_same_color(v[nr][nc], target_color, disabled))
            {
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}

bool is_same_color(char color1, char color2, bool disabled)
{
    if(!disabled) return color1 == color2;
    if(color1 == 'R') return color2 == 'R' || color2 == 'G';
    if(color1 == 'G') return color2 == 'R' || color2 == 'G';
    return color2 == 'B';
}
