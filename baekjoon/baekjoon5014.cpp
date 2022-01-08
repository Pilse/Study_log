#include <iostream>
#include <queue>

using namespace std;

void input();
void bfs();

int F, S, G, U, D;
int Visited[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    bfs();
}

void input()
{
    cin >> F >> S >> G >> U >> D;
}

void bfs()
{
    Visited[S] = 1;
    queue<pair<int, int>> q;
    
    q.push({S, 0});
    
    while(!q.empty())
    {
        int cur_pos = q.front().first;
        int cur_iter = q.front().second;
        
        q.pop();
        
        if(cur_pos == G)
        {
            cout << cur_iter << '\n';
            return;
        }
        
        int up_pos = cur_pos + U;
        int down_pos = cur_pos - D;
        
        if(!(up_pos < 1 || up_pos > F || Visited[up_pos]))
        {
            Visited[up_pos] = 1;
            q.push({ up_pos, cur_iter + 1 });
        }
        
        if(!(down_pos < 1 || down_pos > F || Visited[down_pos]))
        {
            Visited[down_pos] = 1;
            q.push({ down_pos, cur_iter + 1 });
        }
    }
    
    cout << "use the stairs" << '\n';
}
