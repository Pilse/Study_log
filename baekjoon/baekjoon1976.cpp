#include <iostream>

using namespace std;

int map[201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int a, b;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
                map[j][i] = 1;

            if (i == j)
                map[i][j] = 1;
        }
    }

    if (m == 1 || m == 0)
    {
        cout << "YES";
        return 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][k] == 1 && map[k][j] == 1)
                {
                    map[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> b;
        if (i == 1)
        {
            a = b;
            continue;
        }
        else
        {
            if (map[a][b] == 0)
            {
                cout << "NO" << '\n';
                return 0;
            }
            a = b;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
