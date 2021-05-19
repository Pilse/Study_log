#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int n, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a1, a2;
        cin >> n >> m;
        for (int j = 0; j < m; j++)
            cin >> a1 >> a2;
        cout << n - 1 << '\n';
    }
}
