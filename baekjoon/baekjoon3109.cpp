#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int R, C;
int ans = 0;
bool visited[10001][501];
string arr[10001];
int dy[3] = {-1, 0, 1};

bool go(int row, int col)
{
    visited[row][col] = true;
    if (col == C - 1)
    {
        ans++;
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        int next_r = row + dy[i];
        int next_c = col + 1;

        if (next_r < 0 || next_r >= R || visited[next_r][next_c] || arr[next_r][next_c] == 'x')
            continue;

        if (go(next_r, next_c))
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visited, false, sizeof(visited));
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> arr[i];

    for (int i = 0; i < R; i++)
        go(i, 0);

    cout << ans;
}
