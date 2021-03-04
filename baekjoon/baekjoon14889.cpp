#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ability[21][21];
int N;
int tot;
int tot2;
int shortest = 1000000;

void teams(int start, vector<int> vec)
{
    vec.push_back(start);
    
    if(vec.size()==N/2)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            for(int j=i+1;j<vec.size();j++)
            {
                tot += ability[vec[i]][vec[j]];
            }
        }
        
        int flag[21]={0,};
        
        for(int i = 0; i < vec.size(); i++)
        {
            flag[vec[i]] = 1;
        }
        for(int i = 1; i <= N; i++)
        {
            if(flag[i])
                continue;
            for(int j = i + 1; j <= N; j++)
            {
                if(flag[j])
                    continue;
                tot2 += ability[i][j];
            }
        }
        shortest = min(shortest,abs(tot-tot2));
        
        tot=0; tot2=0;
        return;
    }

    for(int i = start + 1 ; i <= N; i++)
    {
        teams(i,vec);
    }
}


void half()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            ability[i][j] += ability[j][i];
            ability[j][i] = ability[i][j];
        }
    }
}

int main()
{
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> ability[i][j];
        }
    }
    half();
    teams(1,v);
    cout<<shortest<<'\n';
}
