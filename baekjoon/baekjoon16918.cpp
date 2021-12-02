#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C, N;
    
    cin >> R >> C >> N;
    
    string arr[201];
    int visited[201][201];
    
    for(int i = 0; i < R; i++)
        cin >> arr[i];
    
    if(N % 2 == 0)
    {
        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cout << 'O';
            }
            cout << '\n';
        }
        
        return 0;
    }
    
    else
    {
        while(N != 1)
        {
            memset(visited, 0, sizeof(visited));
            
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    
                    if(arr[i][j] == '.')
                    {
                        if(visited[i][j]) continue;
                        
                        arr[i][j] = 'O';
                        visited[i][j] = 1;
                    }
                    else
                    {
                        arr[i][j] = '.';
                        visited[i][j] = 1;
                
                        for(int k = 0; k < 4; k++)
                        {
                            int ni = i + dr[k];
                            int nj = j + dc[k];
                            
                            if(ni < 0 || nj < 0 || ni >= R || nj >= C || (!visited[ni][nj] && arr[ni][nj] == 'O')) continue;
                            
                            arr[ni][nj] = '.';
                            visited[ni][nj] = 1;
                        }
                    }
                }
            }
            
            N -= 2;
        }
        
        for(int i = 0; i < R; i++)
            cout << arr[i] << '\n';
        
        return 0;
    }
    
    
}
