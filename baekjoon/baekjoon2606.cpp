#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
int visited[101];
int cnt;

void dfs(int n)
{
    visited[n]=1;
    for(int i=0;i<vec[n].size();i++)
    {
        int w=vec[n][i];
        if(!visited[w])
        {
            cnt++;
            dfs(w);
        }
    }

}

int main()
{
    int computer;
    int number;
    cin>>computer;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        vec[temp1].push_back(temp2);
        vec[temp2].push_back(temp1);
    }

    dfs(1);
    cout<<cnt;
    
}
