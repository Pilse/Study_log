#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int map[60][60];
int visited[60][60]={0,};
vector<pair<int, int>> vec[60][60];

void dps(pair<int, int> cabbage)
{
    visited[cabbage.first][cabbage.second] = 1;
    for (int i = 0; i < vec[cabbage.first][cabbage.second].size(); i++)
    {
        pair<int, int> w = vec[cabbage.first][cabbage.second][i];
        if (!visited[w.first][w.second])
            dps(w);
    }
}
int main()
{
    int testcase = 0;
    int row = 0, col = 0;
    int green = 0;
    int count = 0;

    cin >> testcase;

    for (int a = 0; a < testcase; a++)
    {
        cin >> row >> col >> green;
        for (int b = 0; b < green; b++)
        {
            int x, y;
            cin >> x >> y;
            map[x+1][y+1] = 1;
        }
        for (int i = 1; i < row+1; i++)
        {
            for (int j = 1; j < col+1; j++)
            {
                if (map[i][j] == 1)
                {
                    if (map[i - 1][j] == 1)
                    {
                        vec[i][j].push_back({i - 1, j});
                        vec[i - 1][j].push_back({i, j});
                    }
                    if (map[i + 1][j] == 1)
                    {
                        vec[i][j].push_back({i + 1, j});
                        vec[i + 1][j].push_back({i, j});
                    }
                    if (map[i][j - 1] == 1)
                    {
                        vec[i][j].push_back({i, j - 1});
                        vec[i][j - 1].push_back({i, j});
                    }
                    if (map[i][j + 1] == 1)
                    {
                        vec[i][j + 1].push_back({i, j});
                        vec[i][j].push_back({i, j + 1});
                    }
                }
                
            }
        }
        for (int x = 1; x < row+1; x++)
        {
            for (int y = 1; y < col+1; y++)
            {
                if (!visited[x][y] && map[x][y] )
                {
                    dps({x, y});
                    count++;
                }
            }
        }
        cout << count << endl;
        count = 0;
        for(int i=0;i<60;i++)
        {
            for(int j=0;j<60;j++)
            {
                map[i][j]=0;
                visited[i][j]=0;
            }
        }
        
    }
}
