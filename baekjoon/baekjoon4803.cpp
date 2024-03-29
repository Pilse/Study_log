//1 2 3 4 5 6
//1 2 3 4 5 6

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[501];
queue<pair<int, int> > q;
int visited[501];
int cnt;
int flag;

void isTree(int num)
{
    visited[num] = 1;
    for (int i = 0; i < v[num].size(); i++)
    {
        q.push({v[num][i], num});
        visited[v[num][i]] = 1;
    }

    cnt++;

    while (!q.empty())
    {
        int p = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (int i = 0; i < v[p].size(); i++)
        {
            int w = v[p][i];

            if (visited[w] && parent == w)
                continue;

            if (visited[w])
                flag = 1;

            if (!visited[w])
            {
                q.push({w, p});
                visited[w] = 1;
            }
        }
    }
}

int main()
{
    int t1, t2;
    int node, line;
    int idx{};

    cin >> node >> line;

    while (node != 0 || line != 0)
    {
        idx++;

        for (int i = 0; i < line; i++)
        {
            cin >> t1 >> t2;

            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
        for (int i = 1; i <= node; i++)
        {
            if (!visited[i])
                isTree(i);

            if (flag)
            {
                cnt--;
                flag = 0;
            }
        }
        if (cnt == 0)
            cout << "Case " << idx << ": "
                 << "No trees." << '\n';
        else if (cnt == 1)
            cout << "Case " << idx << ": "
                 << "There is one tree." << '\n';
        else
            cout << "Case " << idx << ": "
                 << "A forest of " << cnt << " trees." << '\n';

        cnt = 0;
        memset(visited, 0, sizeof(int) * (node + 2));
        for (int i = 1; i <= node; i++)
            vector<int>().swap(v[i]);

        cin >> node >> line;
    }
}
