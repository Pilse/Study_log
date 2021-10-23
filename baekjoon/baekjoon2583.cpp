#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int X, Y;
int map[102][102];
int visited[102][102];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
priority_queue<int> pq;

void bfs(int x, int y)
{
    visited[x][y] = 1;
    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    int cnt = 1;
    
    while(!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            
            if(!map[newx][newy] || newx < 1 || newy < 1 || newx > X || newy > Y) continue;
            if(!visited[newx][newy])
            {
                visited[newx][newy] = 1;
                cnt++;
                q.push({newx, newy});
            }
        }
    }
    
    pq.push(-cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    int x1, y1, x2, y2;
    
    cin >> Y >> X >> k;
    
    fill(&map[0][0], &map[101][101], 1);
    
    for(int n = 0; n < k; n++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1 + 1; i <= x2; i++)
        {
            for(int j = y1 + 1; j <= y2; j++)
            {
                map[i][j] = 0;
            }
        }
    }
    
    for(int i = Y; i > 0; i--)
    {
        for(int j = 1; j <= X; j++)
        {
            if(map[j][i] && !visited[j][i])
                bfs(j, i);
        }
    }
    
    cout << pq.size() << '\n';
    
    while(!pq.empty())
    {
        cout << -pq.top() << " ";
        pq.pop();
    }
    
}
