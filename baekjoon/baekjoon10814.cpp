#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

vector<tuple<int, string, int> > v;

bool cmp(tuple<int, string, int> a, tuple<int, string, int> b)
{
    if (get<0>(a) == get<0>(b))
        return get<2>(a) < get<2>(b);
    return get<0>(a) < get<0>(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int age;
    string name;

    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        v.push_back({age, name, i});
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << '\n';
}
