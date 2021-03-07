#include <iostream>

using namespace std;

int mtrx1[110][110];
int mtrx2[110][110];
int mtrx3[110][110];
int R1, C1, R2, C2;

int mul_matrix(int r, int c)
{
    int tot = 0;
    for (int i = 0; i < C1; i++)
    {
        tot += mtrx1[r][i] * mtrx2[i][c];
    }
    return tot;
}

int main()
{

    cin >> R1 >> C1;
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            cin >> mtrx1[i][j];
        }
    }

    cin >> R2 >> C2;
    for (int i = 0; i < R2; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            cin >> mtrx2[i][j];
        }
    }

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            mtrx3[i][j] = mul_matrix(i, j);
        }
    }

    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            cout << mtrx3[i][j] << " ";
        }
        cout << endl;
    }
}
