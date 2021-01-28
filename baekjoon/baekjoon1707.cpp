#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[20010];
queue<int> q;

int visited[20010];
int flag;

void bfs(int n)
{
    visited[n]=1;
    q.push(n);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        
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
        cin>>V,E;
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
                    cout<<'NO'<<endl;
                    return 0;
                }
            }
            memset(visited,0,sizeof(visited));
            queue<int>().swap(q);
        }
    }
    cout<<'YES'<<endl;
}