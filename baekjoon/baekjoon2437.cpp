#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1 1 2 3 6 7 30
// 30 7 6 3 2 1 1
vector<int> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    result = 1;

    for (int i = 0; i < n; i++)
    {
        if (result < v[i])
            break;
        result += v[i];
    }
    cout << result;
}
