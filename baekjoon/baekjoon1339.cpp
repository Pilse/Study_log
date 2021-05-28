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

    int n;
    int idx = 9;
    int tot = 0;
    string str;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int l = (int)str.length();
        for (int j = 0; j < l; j++)
        {
            v[str[j] - 65] += pow(10, l - j - 1);
        }
    }
    sort(v, &v[26], greater<>());

    for (int i = 0; i < 26; i++)
    {
        //cout << v[i] << " ";
        tot += idx-- * v[i];
    }

    cout << tot << '\n';
}
