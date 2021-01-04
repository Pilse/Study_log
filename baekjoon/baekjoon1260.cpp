#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> vec[1001];
int visited[1001];
void dfs(int V)
{
    visited[V] = 1;
    cout << V << " ";
    for (int i = 0; i < vec[V].size(); i++)
    {
        if (!visited[vec[V][i]])
        {
            dfs(vec[V][i]);

        }

    }


}

queue<int> q;
int index = 0;
int pointer = 0;
void bfs(int V)
{
    visited[V] = 1;
    q.push(V);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for (int i = 0; i < vec[temp].size(); i++)
        {
            if (!visited[vec[temp][i]])
            {
                q.push(vec[temp][i]);
                visited[vec[temp][i]] = 1;

            }
        }
    }
}

int main()
{
    int N;
    int M;
    int V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec[temp1].push_back(temp2);
        vec[temp2].push_back(temp1);
    }
    for (int i = 0; i < N; i++)
    {
        sort(vec[i].begin(),vec[i].end());
    }
    dfs(V);
    for (int i = 0; i <= N; i++)
    {
        visited[i] = 0;
    }
    cout << endl;
    bfs(V);
}