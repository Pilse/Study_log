#include <iostream>

using namespace std;

int N;
char tree[70][70];

void zip(int y, int x, int size)
{
    char std = tree[y][x];

    int flag = 0;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if ((std - '0') != (tree[i][j] - '0'))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }

    if (flag)
    {
        cout << "(";
        zip(y, x, size / 2);
        zip(y, x + size / 2, size / 2);
        zip(y + size / 2, x, size / 2);
        zip(y + size / 2, x + size / 2, size / 2);
        cout << ")";
    }
    else
    {
        if (std == '1')
            cout << "1";
        else
            cout << "0";
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", tree[i]);
    }

    zip(0, 0, N);
}
