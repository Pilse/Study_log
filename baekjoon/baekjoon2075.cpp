#include <iostream>
#include <vector>

using namespace std;

void input();
void n_biggest();

int N, Cnt, Ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    n_biggest();
    
}

void input()
{
    cin >> N;
}

void n_biggest()
{
    int map[N][N];
    vector<int> v(N);
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    
    for(int i = 0; i < N; i++)
        v[i] = N - 1;

    
    while(Cnt != N)
    {
        int max_idx = 0;
        int max_val = map[v[0]][0];
        
        for(int i = 1; i < N; i++)
        {
            if(max_val < map[v[i]][i])
            {
                max_idx = i;
                max_val = map[v[i]][i];
            }
        }
        
        Ans = map[v[max_idx]][max_idx];
        
        v[max_idx] -= 1;
        
        Cnt++;
    }
    
    cout << Ans << '\n';
    
}
