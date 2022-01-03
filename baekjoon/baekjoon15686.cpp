#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int r;
    int c;
};

void input();
vector<node> filter(int* arr);
int calc(vector<node> filtered);

int N, M, C, dist;
int map[51][51];
vector<node> chicken;
vector<node> house;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    int arr[C];
    
    for(int i = 0; i < C; i++)
        arr[i] = 0;
    
    for(int i = 0; i < M; i++)
        arr[i] = 1;
    
    do
    {
        vector<node> filtered = filter(arr);
        
        int new_dist = calc(filtered);
        
        dist = dist ? min(dist, new_dist) : new_dist;
        
    } while(prev_permutation(&arr[0], &arr[C]));
    
    cout << dist << '\n';
}

void input()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            
            if(map[i][j] == 2)
                chicken.push_back({i, j});
            
            if(map[i][j] == 1)
                house.push_back({i, j});
        }
    }
    
    C = (int)chicken.size();
}

vector<node> filter(int* arr)
{
    vector<node> filtered;
    
    for(int i = 0; i < C; i++)
    {
        if(arr[i] == 1)
            filtered.push_back(chicken[i]);
    }
    
    return filtered;
}

int calc(vector<node> filtered)
{
    int dist = 0;
    
    for(int i = 0; i < (int)house.size(); i++)
    {
        int hr = house[i].r;
        int hc = house[i].c;
        int temp = 150;
        
        for(int j = 0; j < M; j++)
        {
            int cr = filtered[j].r;
            int cc = filtered[j].c;
            
            temp = min(temp, abs(hr - cr) + abs(hc - cc));
        }
        
        dist += temp;
    }
    
    return dist;
}
