#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

void input();
void init();
double dfs(int visited, int p);

int N;
vector<pair<int, int>> Nodes;
double Dp[65537][17];
double Map[17][17];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(6);
    
    input();
    
    init();
    
    cout << dfs(1, 1) << '\n';
}

void input()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int n1, n2;
        
        cin >> n1 >> n2;
        
        Nodes.push_back({n1, n2});
    }
}

void init()
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            int x_dist = Nodes[i].first - Nodes[j].first;
            int y_dist = Nodes[i].second - Nodes[j].second;
            
            double dist = sqrt(x_dist * x_dist + y_dist * y_dist);
            
            Map[i + 1][j + 1] = dist;
            Map[j + 1][i + 1] = dist;
        }
    }
}

double dfs(int visited, int p)
{
    if(visited == (1 << N) - 1)
        return Map[p][1];
    
    if(Dp[visited][p]) return Dp[visited][p];
    
    Dp[visited][p] = INF;
    
    for(int i = 0; i < N; i++)
    {
        if(visited & (1 << i)) continue;

        int new_visited = visited | (1 << i);
        
        Dp[visited][p] = min(Dp[visited][p], Map[p][i + 1] + dfs(new_visited, i + 1));
    }
    
    return Dp[visited][p];
    
}
