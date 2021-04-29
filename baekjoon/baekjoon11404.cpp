#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

int arr[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n;
    cin >> m;

    fill_n(arr[0], sizeof(arr) / sizeof(int), INF);
    int a, b, c;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        arr[a][b] = min(arr[a][b], c);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                {
                    arr[j][k] = 0;
                    continue;
                }
                if (arr[j][k] > arr[j][i] + arr[i][k])
                {
                    arr[j][k] = arr[j][i] + arr[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}
