#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>

using namespace std;

void init();
void bfs();
bool is_prime(int n);
void get_digit(int n);

int TC, S, T;
int Visited[10001];
int Digit[4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init();
}

void init()
{
    cin >> TC;
    
    while(TC --)
    {
        cin >> S >> T;
        
        bfs();
        
        memset(Visited, 0, sizeof(Visited));
    }
}

bool is_prime(int n)
{
    if (n < 2) return false;
    
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    
    return true;
}

void get_digit(int n)
{
    Digit[0] = n / 1000;
    Digit[1] = n / 100 - Digit[0] * 10;
    Digit[2] = n / 10 - (Digit[0] * 100 + Digit[1] * 10);
    Digit[3] = n - (n / 10) * 10;
}

int get_new_num(int digit, int replace)
{
    switch (digit) {
        case 0:
            return replace * 1000 + Digit[1] * 100 + Digit[2] * 10 + Digit[3];
            break;
        case 1:
            return Digit[0] * 1000 + replace * 100 + Digit[2] * 10 + Digit[3];
            break;
        case 2:
            return Digit[0] * 1000 + Digit[1] * 100 + replace * 10 + Digit[3];
            break;
        case 3:
            return Digit[0] * 1000 + Digit[1] * 100 + Digit[2] * 10 + replace;
            break;
            
        default:
            return 0;
    }
    
}

void bfs()
{
    Visited[S] = 1;
    
    queue<pair<int, int>> q;
    
    q.push({S, 0});
    
    while(!q.empty())
    {
        int cur_prime = q.front().first;
        int cur_iter = q.front().second;
        
        q.pop();
        
        if(cur_prime == T)
        {
            cout << cur_iter << '\n';
            return;
        }
        
        get_digit(cur_prime);
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(i == 0 && j == 0) continue;
                
                int new_num = get_new_num(3 - i, j);
                
                if(new_num >= 1000 && !Visited[new_num] && is_prime(new_num))
                {
                    Visited[new_num] = 1;
                    q.push({ new_num, cur_iter + 1 });
                    
                }
            }
        }
    }
    
    cout << "Impossible" << '\n';
}
