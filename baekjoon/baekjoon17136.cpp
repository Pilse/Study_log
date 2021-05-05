#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;

pair<int, int> arr[11][11];
int one = 5;
int two = 5;
int three = 5;
int four = 5;
int five = 5;
int cnt;

int isN(int y, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (y + i > 10 || x + n - 1 > 10)
            return 0;
        if (arr[y + i][x + n - 1].first == 0)
            return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (y + n - 1 > 10 || x + i > 10)
            return 0;
        if (arr[y + n - 1][x + i].first == 0)
            return 0;
    }

    for (int i = 0; i < n; i++)
    {
        arr[y + i][x + n - 1].second = 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[y + n - 1][x + i].second = 1;
    }
    return 1;
}

int getSize(int y, int x)
{
    int i = 2;
    int size;
    switch (i)
    {
    case 2:
        size = two;
        break;
    case 3:
        size = three;
        break;
    case 4:
        size = four;
        break;
    case 5:
        size = five;
        break;
    default:
        size = one;
        break;
    }
    while (i <= 5 && isN(y, x, i) && size > 0)
        i++;

    return i - 1;
}

void paper()
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (arr[y][x].second == 0)
        {
            arr[y][x].second = 1;
            cout << y << " " << x << '\n';
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 1; j <= 10; j++)
                {
                    cout << arr[i][j].second << " ";
                }
                cout << '\n';
            }
            int size = getSize(y, x);
            cout << size << '\n';
            cout << '\n';
            switch (size)
            {
            case 1:
                one--;
                if (one < 0)
                {
                    cnt = -1;
                    return;
                }
                cnt++;
                break;
            case 2:
                two--;
                cnt++;
                break;
            case 3:
                three--;
                cnt++;
                break;
            case 4:
                four--;
                cnt++;
                break;
            case 5:
                five--;
                cnt++;
                break;
            default:
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int t;
            cin >> t;
            arr[i][j] = {t, 0};
            if (t == 1)
                q.push({i, j});
        }
    }

    paper();
    cout << cnt << '\n';
}
