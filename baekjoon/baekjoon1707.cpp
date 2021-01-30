#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[20010];
queue<int> q;

int visited[20010];
int flag;
int iter;

void bfs(int n)
{
    visited[n]=1;
    q.push(n);
    while(!q.empty())
    {
        if(flag)
            break;
        iter++;
        int p = q.front();
        q.pop();
        for(int i=0 ; i< v[p].size();i++)
        {
            int w = v[p][i];
            if(v[w].size()<2) continue;
            if(visited[w] && iter==2 && w!=n)
            {
                flag=1;
                break;
            }
            if(!visited[w])
            {
                visited[w]=1;
                q.push(w);
            }
            
        }
    }

}

int main()
{
    int T;
    int V,E;
    int temp1,temp2;

    cin >> T;

    for(int i=0;i<T;i++)
    {
        cin>>V>>E;
        for(int j=0;j<E;j++)
        {
            cin>>temp1>>temp2;
            v[temp1].push_back(temp2);
            v[temp2].push_back(temp1);
        }

        for(int k=1;k<V;k++)
        {
            if(v[k].size()>1)
            {
                bfs(k);
                if(flag)
                {
                    printf("NO\n");
                    break;
                }
            }
            iter=0;
            memset(visited,0,sizeof(visited));
        }
        if(!flag)
            printf("YES\n");
        queue<int>().swap(q);
        for(int x=1;x<V+1;x++)
            vector<int>().swap(v[x]);
        flag=0;
        
    }
}

