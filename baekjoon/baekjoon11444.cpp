#include <iostream>
#include <algorithm>
#define N 2
#define mod 1000000007
using namespace std;

long long B;

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
                tot = ((tot % mod) + (mtrx2[i][k]%mod) * (mtrx2[k][j]%mod) % mod) % mod;
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
                tot = ((tot % mod) + (mtrx2[i][k]%mod) * (matrix[k][j]%mod) % mod) % mod;
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

    cin >> B;
    
    mtrx1[0][0] = 1;
    mtrx1[0][1] = 1;
    mtrx1[1][0] = 1;
    mtrx1[1][1] = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mtrx2[i][j] = mtrx1[i][j];
        }
    }
    modular(B);
    cout<<mtrx2[1][0]<<endl;
}
