#include <iostream>
#define INF 987654321

using namespace std;
int arr[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 401; i++)
    {
        for (int j = 0; j < 401; j++)
        {
            if (i == j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
        }
    }

    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (arr[i][k] != INF && arr[k][j] != INF)
                {
                    if (arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    int least = INF;

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (arr[i][j] != INF && i != j)
            {
                if (arr[j][i] != INF)
                    least = min(least, arr[i][j] + arr[j][i]);
            }
        }
    }
    if (least == INF)
        cout << -1 << '\n';
    else
        cout << least << '\n';
}
