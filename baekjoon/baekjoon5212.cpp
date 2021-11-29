#include <iostream>
#include <vector>
#include <string>

#define INF 987654321

using namespace std;

int dr[] = {0, 1, 0 ,-1};
int dc[] = {1, 0, -1 , 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C;
    vector<string> v;
    vector<pair<int, int>> ans;
    string temp;
    
    cin >> C >> R;
    
    for(int i = 0; i < C; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    
    for(int i = 0; i < C; i++)
    {
        for(int j = 0; j < R; j++)
        {
            char ch = v[i][j];
            
            if(ch == 'X')
            {
                int cnt = 0;
                
                for(int n = 0; n < 4; n++)
                {
                    int ni = i + dc[n];
                    int nj = j + dr[n];
                    
                    if(ni < 0 || nj < 0 || ni >= C || nj >= R)
                    {
                        cnt ++;
                        continue;
                    }
                    
                    if(v[ni][nj] == '.')
                        cnt++;
                }
                
                if(cnt < 3)
                    ans.push_back({i, j});
            }
        }
    }
    
    int min_c = INF;
    int min_r = INF;
    int max_c = -1;
    int max_r = -1;
    
    for(int i = 0; i < ans.size(); i++)
    {
        int cur_c = ans[i].first;
        int cur_r = ans[i].second;
        
        if(cur_c < min_c)
            min_c = cur_c;
        if(cur_c > max_c)
            max_c = cur_c;
        if(cur_r < min_r)
            min_r = cur_r;
        if(cur_r > max_r)
            max_r = cur_r;
    }
    
    int idx = 0;
    int cur_c = ans[idx].first;
    int cur_r = ans[idx].second;
    
    for(int i = min_c; i <= max_c; i++)
    {
        for(int j = min_r; j <= max_r; j++)
        {
            if(i == cur_c && j == cur_r)
            {
                cout << 'X';
                idx++;
                cur_c = ans[idx].first;
                cur_r = ans[idx].second;
                
            }
            else
                cout << '.';
        }
        cout << '\n';
    }
        
}
