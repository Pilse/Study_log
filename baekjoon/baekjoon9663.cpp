#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > v;
int visited[20][20];
int q[20][20];
int cnt;
int N;

void delete_line(int y, int x)
{
    for (int i = 0; i < N; i++)
    {
        visited[i][x]--;
        visited[y][i]--;
        for (int j = 0; j < N; j++)
        {
            if (abs(y - i) == abs(x - j))
            {
                visited[i][j]--;
            }
        }
    }
}

void add_line(int y, int x)
{
    for (int i = y; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            
            if(q[i][j]==1 && !(i==y && j==x))
            {
                delete_line(i,j);
                q[i][j]=0;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        visited[i][x]++;
        visited[y][i]++;
        for (int j = 0; j < N; j++)
        {
            if (abs(y - i) == abs(x - j))
            {
                visited[i][j]++;
            }
        }
    }
}


void queen()
{
    for (int i = 0; i < N; i++)
    {
        v.push_back(make_pair(0,i));
    }
    
    while (v.size() > 0)
    {
        
        pair<int, int> t = v[v.size() - 1];
        q[t.first][t.second]=1;
        v.pop_back();
        if (t.first == N - 1)
        {
            add_line(t.first, t.second);
            cnt++;
        }
        else
        {
            add_line(t.first, t.second);
            for (int i = 0; i < N; i++)
            {
                if (!visited[t.first + 1][i])
                    v.push_back(make_pair(t.first + 1, i));
            }
        }
    }
}

int main()
{

    cin >> N;
    queen();
    cout << cnt << endl;

    return 0;
}
