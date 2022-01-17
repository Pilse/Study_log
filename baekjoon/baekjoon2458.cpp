#include <iostream>

using namespace std;

void input();
void floyd_warshall();
bool check(int n);

int N, M, Tot;
int Map[501][501];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    floyd_warshall();
    
    for(int i = 1; i <= N; i++)
        if(check(i)) Tot++;
    
    cout << Tot << '\n';
}

void input()
{
    cin >> N >> M;
    
    for(int i = 0; i < M; i++)
    {
        int r, c;
        
        cin >> r >> c;
        
        Map[r][c] = 1;
    }
}

void floyd_warshall()
{
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(Map[i][j] || i == j) continue;
                
                if(Map[i][k] && Map[k][j]) Map[i][j] = 1;
                
            }
        }
    }
}

bool check(int n)
{
    for(int i = 1; i <= N; i++)
    {
        if(i == n) continue;
        
        if(Map[i][n] + Map[n][i] != 1)
            return false;
    }
    
    return true;
}
