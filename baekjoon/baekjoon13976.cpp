#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator*(matrix &a, matrix &b)
{
    long long r = a.size();
    long long c = b[0].size();
    long long n = a[0].size();
    matrix ret(n, vector<long long>(n, 0));
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            for(int k = 0; k < n; k++)
            {
                ret[i][j] += (a[i][k] * b[k][j]) % 1000000007;
                ret[i][j] = (ret[i][j] + 1000000007) % 1000000007;
            }
    
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    matrix U {{1}, {1}};
    matrix A {{4, -1}, {1, 0}};
    matrix I {{1, 0}, {0, 1}};
    
    if(n & 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    
    while(n)
    {
        n /= 2;
        if(n % 2 == 1) I = I * A;
        A = A * A;
    }
    
    matrix ans = I * U;
    cout << ans[0][0] << '\n';
}
