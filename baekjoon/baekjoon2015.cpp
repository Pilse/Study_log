#include <iostream>
#include <map>

using namespace std;

int arr[200001];
int acc[200001];
map<int, int> m;

int main()
{
    int n, k;
    long long result{};
    cin >> n >> k;

    m[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        acc[i] = acc[i - 1] + arr[i];

        if (m[acc[i] - k] > 0)
            result += m[acc[i] - k];

        m[acc[i]]++;
    }

    cout << result << '\n';
}
