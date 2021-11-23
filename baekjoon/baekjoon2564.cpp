#include <iostream>
#include <vector>

using namespace std;

int X, Y;

int getDirInfo(int cop, int store)
{
    // 1 X수평, 2 Y수평, 3 수직, 4 같다
    if(cop + store == 3)
        return 1;
    
    else if(cop + store == 7)
        return 2;
    
    else if(cop == store)
        return 4;
    
    else return 3;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> X >> Y;
    
    int n, t1, t2;
    int tot = 0;
    vector<pair<int, int>> store;
    pair<int, int> cop;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        store.push_back({t1, t2});
    }
    
    cin >> t1 >> t2;
    
    cop = {t1, t2};
    
    for(int i = 0; i < store.size(); i++)
    {
        int dir = store[i].first;
        int pos = store[i].second;
        
        // 동근이의 dir과 상점의 dir이 수평, 수직, 같은지를 확인
        int dirInfo = getDirInfo(cop.first, dir);
        // X수평이라면 + Y,
        if(dirInfo == 1)
        {
            tot += Y;
            tot += min(pos + cop.second, (X - pos) + (X - cop.second));
        }
        
        // Y수평이라면 + X,
        else if(dirInfo == 2)
        {
            tot += X;
            tot += min(pos + cop.second, (Y - pos) + (Y - cop.second));
        }
        
        // 수직이라면
        else if(dirInfo == 3)
        {
            // 상점 dir이 1이라면 + 동근 pos
            if(dir == 1)
            {
                tot += cop.second;
                // 동근 dir이 3이라면 + 상점 pos
                if(cop.first == 1)
                    tot += pos;
                // 아니라면 + X - 상점 pos
                else
                    tot += X - pos;
            }
            
            // 상점 dir이 2라면 + Y - 동근 pos
            else if(dir == 2)
            {
                tot += Y - cop.second;
                // 동근 dir이 3이라면 + 상점 pos
                if(cop.first == 1)
                    tot += pos;
                // 아니라면 + X - 상점 pos
                else
                    tot += X - pos;
            }
            // 상점 dir이 3이라면 + 동근 pos
            else if(dir == 3)
            {
                tot += cop.second;
                // 동근 dir이 1이라면 + 상점 pos
                if(cop.first == 1)
                    tot += pos;
                // 아니라면 + Y - 상점 pos
                else
                    tot += Y - pos;
            }
            
            // 상점 dir이 4라면 + X - 동근 pos
            else if(dir == 4)
            {
                tot += X - cop.second;
                // 동근 dir이 1이라면 + 상점 pos
                if(cop.first == 1)
                    tot += pos;
                // 아니라면 + Y - 상점 pos
                else
                    tot += Y - pos;
            }
        }
        
        // 같다면
        else
        {
            // | 상점 pos - 동근 pos |
            tot += abs(pos - cop.second);
        }
    }
    
    cout << tot << '\n';
}
