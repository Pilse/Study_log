#include <iostream>
#include <queue>

using namespace std;
int arr[17][16];
int cnt;
int enemy;
int n, m, d;
int state = 1;
queue<pair<int, int> > q;
queue<pair<int, int> > q1;

void castle(int a, int b, int c)
{
    while (enemy > 0)
    {
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= i * 2 - 1; j++)
            {
                if (arr[n + 1 - j][a + j - i] == 1)
                {
                    cnt++;
                    enemy--;
                    arr[n + 1 - j][a + j - i] = 0;
                }
            }
        }
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= i * 2 - 1; j++)
            {
                if (arr[n + 1 - j][b + j - i] == 1)
                {
                    cnt++;
                    enemy--;
                    arr[n + 1 - j][b + j - i] = 0;
                }
            }
        }
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= i * 2 - 1; j++)
            {
                if (arr[n + 1 - j][c + j - i] == 1)
                {
                    cnt++;
                    enemy--;
                    arr[n + 1 - j][c + j - i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << arr[i][j] << " ";
                if (arr[i][j] == 1)
                {
                    if (i == n)
                    {
                        arr[i][j] = 0;
                        enemy--;
                    }
                    else
                    {
                        arr[i][j] = 0;
                        arr[i + 1][j] = 1;
                    }
                }
            }
            cout << "\n";
        }
        if (state == 1)
        {
            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (y == n)
                {
                    arr[y][x] = 0;
                    enemy--;
                }
                else
                {
                    arr[y][x] = 0;
                    arr[y + 1][x] = 1;
                    q1.push({y + 1, x});
                }
            }
        }
        else
        {
            while (!q1.empty())
            {
                int y = q1.front().first;
                int x = q1.front().second;
                q1.pop();

                if (y == n)
                {
                    arr[y][x] = 0;
                    enemy--;
                }
                else
                {
                    arr[y][x] = 0;
                    arr[y + 1][x] = 1;
                    q.push({y + 1, x});
                }
            }
        }
        state *= -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                enemy++;
                q.push({i, j});
            }
        }
    }
    int result{};

    for (int i = 1; i <= m - 2; i++)
    {
        for (int j = i + 1; j <= m - 1; j++)
        {
            for (int k = j + 1; k <= m; k++)
            {
                castle(i, j, k);
                result = max(result, cnt);
                cnt = 0;
            }
        }
    }

    cout << result << '\n';
}
