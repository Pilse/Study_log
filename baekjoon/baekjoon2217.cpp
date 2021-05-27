#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, temp;
    int maximum = 0;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < v.size(); i++)
    {
        int newMax = v[i] * (i + 1);
        maximum = max(maximum, newMax);
    }

    cout << maximum << '\n';
}
