#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[20100];
queue<int> q;
pair<int, int> visited[20100];
int flag;

void bfs(int n)
{
    visited[n] = {1, -1};
    q.push(n);
    int status = 1;
    while (!q.empty())
    {
        if (flag)
            break;
        int p = q.front();
        status = visited[p].second;
        q.pop();
        for (int i = 0; i < v[p].size(); i++)
        {
            int w = v[p][i];
            if (visited[w].first && visited[w].second == status)
            {
                flag = 1;
                break;
            }
            if (!visited[w].first)
            {
                visited[w] = {1, status * (-1)};
                q.push(w);
            }
        }
    }
}

int main()
{
    int K;
    cin >> K;
    int V, E;
    int temp1, temp2;
    for (int i = 0; i < K; i++)
    {
        cin >> V >> E;
        for (int j = 0; j < E; j++)
        {
            cin >> temp1 >> temp2;
            v[temp1].push_back(temp2);
            v[temp2].push_back(temp1);
        }
        for (int k = 0; k < V; k++)
        {
            if (v[k].size() > 0 && !visited[k].first)
                bfs(k);
            if (flag)
            {
                printf("NO\n");
                break;
            }
        }
        if(!flag)
             printf("YES\n");
        flag = 0;
        queue<int>().swap(q);
        for (int l = 1; l < V + 1; l++)
            vector<int>().swap(v[l]);
        memset(visited, 0, sizeof(visited));
    }
}
