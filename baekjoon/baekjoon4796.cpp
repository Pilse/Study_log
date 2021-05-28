#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int v[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, p, v;
    int idx = 1;
    cin >> l >> p >> v;

    while (!(l == 0 && p == 0 && v == 0))
    {
        int q = v / p;
        int extra = (v % p) > l ? l : v % p;
        int result = q * l + extra;
        cout << "Case " << idx++ << ": " << result << '\n';
        cin >> l >> p >> v;
    }
}
