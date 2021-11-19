#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

vector<pair<int, int>> vec[20001];
int v, e;
int dist[20001];

void dijk(int s)
{
    for(int i = 1; i <= v; i++)
        dist[i] = INF;
    dist[s] = 0;
    
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, s});
    
    while(!pq.empty())
    {
        int w = -pq.top().first;
        int c = pq.top().second;
        pq.pop();
        
        if(w > dist[c]) continue;
        
        for(int i = 0; i < vec[c].size(); i++)
        {
            int nc = vec[c][i].first;
            int nw = vec[c][i].second;
            
            if(w + nw < dist[nc])
            {
                dist[nc] = w + nw;
                pq.push({-(nw + w), nc});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int s;
    
    cin >> v >> e;
    cin >> s;
    
    int t1, t2, tw;
    
    for(int i = 0; i < e; i++)
    {
        cin >> t1 >> t2 >> tw;
        vec[t1].push_back({t2, tw});
    }
    
    dijk(s);
    
    for(int i = 1; i <= v; i++)
    {
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}
