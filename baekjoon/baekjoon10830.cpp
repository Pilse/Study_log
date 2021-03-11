#include <iostream>
#include <algorithm>
using namespace std;

long long N ,B;

long long mtrx1[110][110];
long long mtrx2[110][110];
long long mtrx3[110][110];


void align_matrix(long long matrix1[][110], long long matrix2[][110])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix1[i][j] = matrix2[i][j];
        }
    }
}
void square_matrix()
{
    long tot = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                tot = ((tot % 1000) + (mtrx2[i][k]%1000) * (mtrx2[k][j]%1000) % 1000) % 1000;
            }
            mtrx3[i][j] = tot;
            tot = 0;
        }
    }
    align_matrix(mtrx2,mtrx3);
}
void mul_matrix(long long matrix[][110])
{
    long tot = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                tot = ((tot % 1000) + (mtrx2[i][k]%1000) * (matrix[k][j]%1000) % 1000) % 1000;
            }
            mtrx3[i][j] = tot;
            tot = 0;
        }
    }
    align_matrix(mtrx2,mtrx3);
}


void modular(long long B)
{
    if(B==1)
        return;
    if(B%2==0)
    {
        square_matrix();
        modular(B/2);
    }
    else
    {
        long long mtrx4[110][110];
        align_matrix(mtrx4,mtrx2);
        square_matrix();
        modular((B-1)/2);
        mul_matrix(mtrx4);
    }
}

int main()
{

    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mtrx1[i][j];
            mtrx2[i][j] = mtrx1[i][j];
        }
    }
    modular(B);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mtrx2[i][j]%1000 <<" ";
        }
        cout<<endl;
    }



}