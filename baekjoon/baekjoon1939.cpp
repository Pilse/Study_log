#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

struct edge {
    int b;
    int cost;
};

using namespace std;

void input();
int bfs(int cur_cost);

int N, M;
int A, B, C;
int max_cost;
int start, dest;
int visited[100001];
vector<edge> vec[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
        
    input();
    
    int left = 0;
    int right = max_cost;
    
    while(left <= right)
    {
        memset(visited, 0, sizeof(visited));
        int mid = (left + right) / 2;
        
        if(bfs(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    cout << right << '\n';
}

void input()
{
    cin >> N >> M;
    
    for(int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        
        vec[a].push_back({b, cost});
        vec[b].push_back({a, cost});
        
        max_cost = max(max_cost, cost);
    }
    
    cin >> start >> dest;
}

int bfs(int cur_cost)
{
    queue<edge> q;
    visited[start] = 1;
    
    q.push({start, 1000000001});
    
    while(!q.empty())
    {
        int cur = q.front().b;
        
//        cout << cur << " ";
        
        q.pop();
        
        if(cur == dest)
            return 1;
        
        for(int i = 0; i < vec[cur].size(); i++)
        {
            edge w = vec[cur][i];
            
            if(!visited[w.b] && w.cost >= cur_cost)
            {
                visited[w.b] = 1;
                q.push({w.b, w.cost});
            }
        }
    }
    
    return 0;
}
