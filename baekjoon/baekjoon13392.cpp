#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

string source, target;
int dp[11][10001];

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
    dp[rotated][cur] = min(dp[rotated][cur], rotate((rotated + l_rotated) % 10, cur + 1) + l_rotated);
    dp[rotated][cur] = min(dp[rotated][cur], rotate(rotated, cur + 1) + r_rotated);
    
    return dp[rotated][cur];
}
