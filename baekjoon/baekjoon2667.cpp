#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char map[26][26];
int visited[26][26];
int N;
int total;
int countNumber;
vector<pair<int,int>> vec[26][26];
queue<pair<int,int>> q;

int bfs(pair<int,int> house)
{
    visited[house.first][house.second]=1;
    q.push({house.first,house.second});
    while(!q.empty())
    {
        countNumber++;
        pair<int,int> p=q.front();
        q.pop();
        for(int i=0;i<vec[p.first][p.second].size();i++)
        {
            pair<int,int> w = vec[p.first][p.second][i];
            if(!visited[w.first][w.second])
            {
                visited[w.first][w.second]=1;
                q.push(w);
            }
        }
    }
    return countNumber;
}

int main()
{
    cin >> N;
    int index = 0;
    int cnt[676] = {
        0,
    };

    for (int j = 1; j < N + 1; j++)
    {
        scanf("%s", map[j] + 1);
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (map[i][j] == '1')
            {
                if (map[i - 1][j] == '1')
                {
                    vec[i][j].push_back({i - 1, j});
                    vec[i - 1][j].push_back({i, j});
                }
                if (map[i + 1][j] == '1')
                {
                    vec[i][j].push_back({i + 1, j});
                    vec[i + 1][j].push_back({i, j});
                }
                if (map[i][j - 1] == '1')
                {
                    vec[i][j].push_back({i, j - 1});
                    vec[i][j - 1].push_back({i, j});
                }
                if (map[i][j + 1] == '1')
                {
                    vec[i][j + 1].push_back({i, j});
                    vec[i][j].push_back({i, j + 1});
                }
            }
        }
    }
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (!visited[i][j] && map[i][j] == '1')
            {
                cnt[index++] = bfs({i, j});
                total++;
                countNumber = 0;
            }
        }
    }
    sort(cnt, cnt + index);
    cout << total << endl;
    for (int i = 0; i < total; i++)
    {
        cout << cnt[i] << endl;
    }
}
