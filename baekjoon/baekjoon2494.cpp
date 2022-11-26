#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

string source, target;
int dp[11][10001];
int mem[11][10001];

int rotate(int rotated, int cur);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin >> source >> target;
    
    memset(dp, -1, sizeof(dp));
    cout << rotate(0, 0) << '\n';
    
    int l_rotated = 0;
    for(int i = 0; i < n; i++)
    {
        if(mem[l_rotated][i] > 0)
        {
            cout << i + 1 << " " << mem[l_rotated][i]<< '\n';
            l_rotated = (l_rotated + mem[l_rotated][i]) % 10;
            continue;
        }
        
        cout << i + 1 << " " << mem[l_rotated][i] << '\n';
    }
}

int rotate(int rotated, int cur)
{
    if(cur == target.length()) return 0;
    if(dp[rotated][cur] != -1) return dp[rotated][cur];
    
    int cur_num = ((source[cur] - '0') + rotated) % 10;
    int target_num = target[cur] - '0';
    int diff = abs(cur_num - target_num);
    int l_rotated = cur_num > target_num ? 10 - diff : diff;
    int r_rotated = cur_num >= target_num ? diff : 10 - diff;
    
    dp[rotated][cur] = 1e8;
    int l_result = rotate((rotated + l_rotated) % 10, cur + 1) + l_rotated;
    if(dp[rotated][cur] > l_result)
    {
        dp[rotated][cur] = l_result;
        mem[rotated][cur] = l_rotated;
    }
    int r_result = rotate(rotated, cur + 1) + r_rotated;
    if(dp[rotated][cur] > r_result)
    {
        dp[rotated][cur] = r_result;
        mem[rotated][cur] = -r_rotated;
    }
    
    return dp[rotated][cur];
}
