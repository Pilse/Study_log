#include <iostream>
using namespace std;
int arr[11][11];
int arr_state[11][11];
int ret;
int n[5] = {5, 5, 5, 5, 5};
bool temp_state = false;

void update(int r, int c, int length, int onetwo)
{
    for (int i = r; i < r + length; i++)
    {
        for (int j = c; j < c + length; j++)
        {
            arr[i][j] = onetwo;
        }
    }
}

bool check(int r, int c, int length)
{
    for (int i = r; i < r + length; i++)
    {
        for (int j = c; j < c + length; j++)
        {
            if (arr[i][j] == 0 || arr[i][j] == 2)
                return false;
        }
    }
    return true;
}

void dfs(int r, int c, int depth)
{

    int temp = 0;
    for (int i = r; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 1)
            {
                r = i;
                c = j;
                temp = 1;

                break;
            }
        }
        if (temp == 1)
            break;
    }

    if (temp == 0)
    {
        if (ret > depth)
        {
            ret = depth;
        }
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        if (n[i - 1] == 0)
            continue;
        if (check(r, c, i) == false)
            return;
        else
            n[i - 1]--;
        update(r, c, i, 2);
        dfs(r, c, depth + 1);
        n[i - 1]++;
        update(r, c, i, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ret = 30;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                temp_state = true;
        }
    }

    dfs(0, 0, 0);
    if (temp_state == true && ret == 30)
        cout << -1;
    else
        cout << ret;
    return 0;
}
#include <iostream>
using namespace std;
int arr[11][11];
int arr_state[11][11];
int ret;
int n[5] = {5, 5, 5, 5, 5};
bool temp_state = false;

void update(int r, int c, int length, int onetwo)
{
    for (int i = r; i < r + length; i++)
    {
        for (int j = c; j < c + length; j++)
        {
            arr[i][j] = onetwo;
        }
    }
}

bool check(int r, int c, int length)
{
    for (int i = r; i < r + length; i++)
    {
        for (int j = c; j < c + length; j++)
        {
            if (arr[i][j] == 0 || arr[i][j] == 2)
                return false;
        }
    }
    return true;
}

void dfs(int r, int c, int depth)
{

    int temp = 0;
    for (int i = r; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 1)
            {
                r = i;
                c = j;
                temp = 1;

                break;
            }
        }
        if (temp == 1)
            break;
    }

    if (temp == 0)
    {
        if (ret > depth)
        {
            ret = depth;
        }
        return;
    }

    for (int i = 1; i <= 5; i++)
    {
        if (n[i - 1] == 0)
            continue;
        if (check(r, c, i) == false)
            return;
        else
            n[i - 1]--;
        update(r, c, i, 2);
        dfs(r, c, depth + 1);
        n[i - 1]++;
        update(r, c, i, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ret = 30;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                temp_state = true;
        }
    }

    dfs(0, 0, 0);
    if (temp_state == true && ret == 30)
        cout << -1;
    else
        cout << ret;
    return 0;
}
