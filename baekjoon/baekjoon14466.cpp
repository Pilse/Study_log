#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void bfs(int r, int c);
bool can_move_to(int r, int c, int dir);

int N, R, K, Cnt;
pair<int, vector<int>> Map[101][101];
vector<pair<int, int>> Node;
int Dr[4] = {-1, 0, 1, 0};
int Dc[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    for(int i = 0; i < K; i++)
        bfs(Node[i].first, Node[i].second);
    
    cout << Cnt / 2 << '\n';
}

void input()
{
    cin >> N >> K >> R;
    
    for(int i = 1; i <= R; i++)
    {
        int r1, c1, r2, c2;
        
        cin >> r1 >> c1 >> r2 >> c2;
        
        for(int i = 0; i < 4; i++)
        {
            if(r1 + Dr[i] == r2 && c1 + Dc[i] == c2)
            {
                Map[r1][c1].second.push_back(i);
                Map[r2][c2].second.push_back(i > 1 ? i - 2 : i + 2);
                
                break;
            }
        }
    }
    
    for(int i = 1; i <= K; i++)
    {
        int r, c;
        
        cin >> r >> c;
        
        Map[r][c].first = 1;
        
        Node.push_back({r, c});
    }
}

void bfs(int r, int c)
{
    int visited[101][101] {0};
    int cnt = K;
    queue<pair<int, int>> q;
    
    visited[r][c] = 1;
    
    q.push({r, c});
    
    while(!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        
        q.pop();
        
        if(Map[cur_r][cur_c].first == 1)
            cnt--;
        
        for(int i = 0; i < 4; i++)
        {
            if(!can_move_to(cur_r, cur_c, i)) continue;
            
            int next_r = cur_r + Dr[i];
            int next_c = cur_c + Dc[i];
            
            if(next_r < 1 || next_c < 1 || next_r > N || next_c > N) continue;
            
            if(!visited[next_r][next_c])
            {
                visited[next_r][next_c] = 1;
                
                q.push({next_r, next_c});
            }
        }
    }
    
    Cnt += cnt;
}

bool can_move_to(int r, int c, int dir)
{
    for(int i = 0; i < Map[r][c].second.size(); i++)
    {
        if(dir == Map[r][c].second[i])
            return false;
    }
    
    return true;
}
