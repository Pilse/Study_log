#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int a;
    int b;
};

int arr1[51][51];
int arr2[51][51];
int n, m;
int tot;
queue<node> q;

void flip_flop(node coor)
{
    int y = coor.a;
    int x = coor.b;

    for (int i = y; i < y + 3; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            arr1[i][j] ^= 1;
        }
    }
}

void matrix()
{
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                flip_flop({i, j});
                tot++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr1[i][j] = str[j] - 48;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr2[i][j] = str[j] - 48;
        }
    }

    matrix();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i][j] != arr2[i][j])
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << tot << '\n';
}
