#include <iostream>
#define MOD 1000000007

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long p, n;
    cin >> p >> n;
    long long *v = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long long result = v[0] % MOD;

    for (int i = 1; i < n; i++)
        result = ((result * p) % MOD + (v[i] % MOD)) % MOD;

    cout << result << endl;

    return 0;
}