#include <vector>

using namespace std;

int MOD = 20170805;

struct dir {
    int right;
    int bottom;
};

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<dir>> dirs(m, vector<dir>(n, {0, 0}));

    for(int i = 0; i < m; i++)
    {
        if(city_map[i][0] == 1) break;

        dirs[i][0].bottom = 1; 
        dirs[i][0].right = city_map[i][0] ? 0 : 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(city_map[0][i] == 1) break;

        dirs[0][i].bottom = city_map[0][i] ? 0 : 1; 
        dirs[0][i].right = 1;
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(city_map[i][j] == 1)
            {
                dirs[i][j] = {0, 0};
                continue;
            }

            if(city_map[i][j] == 2)
            {
                dirs[i][j] = {dirs[i][j - 1].right, dirs[i - 1][j].bottom};
                continue;
            }

            int cases = (dirs[i][j - 1].right + dirs[i - 1][j].bottom) % MOD;
            dirs[i][j] = {cases, cases};
        }
    }

    return dirs[m - 1][n - 1].bottom;
}