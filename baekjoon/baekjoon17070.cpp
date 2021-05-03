#include <iostream>
#include <vector>

using namespace std;

int arr[17][17];
int state; //0 가로 1 세로 2 대각
int cnt;
int n;

void find_way(int y, int x, int state)
{
    if (y == n && x == n)
    {
        cnt++;
        return;
    }
    if (state == 0)
    {
        if (x + 1 <= n && arr[y][x + 1] != 1)
            find_way(y, x + 1, 0);
        if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] != 1 && arr[y + 1][x] != 1 && arr[y + 1][x + 1] != 1)
            find_way(y + 1, x + 1, 2);
    }
    if (state == 1)
    {
        if (y + 1 <= n && arr[y + 1][x] != 1)
            find_way(y + 1, x, 1);
        if (y + 1 <= n && x + 1 <= n && arr[y][x + 1] != 1 && arr[y + 1][x + 1] != 1 && arr[y + 1][x] != 1)
            find_way(y + 1, x + 1, 2);
    }
    if (state == 2)
    {
        if (x + 1 <= n && arr[y][x + 1] != 1)
            find_way(y, x + 1, 0);
        if (y + 1 <= n && arr[y + 1][x] != 1)
            find_way(y + 1, x, 1);
        if (x + 1 <= n && y + 1 <= n && arr[y][x + 1] != 1 && arr[y + 1][x] != 1 && arr[y + 1][x + 1] != 1)
            find_way(y + 1, x + 1, 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    find_way(1, 2, 0);

    cout << cnt << '\n';
}
