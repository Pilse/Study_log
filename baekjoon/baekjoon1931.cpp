#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > v;

bool cmp(pair<int, int> v1, pair<int, int> v2)
{
    if (v1.second == v2.second)
        return v1.first < v2.first;
    return v1.second < v2.second;
}

int main()
{
    int n;
    int temp1, temp2;
    int cnt = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        v.push_back(make_pair(temp1, temp2));
    }
    sort(v.begin(), v.end(), cmp);

    int idx = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[idx].second <= v[i].first)
        {
            idx = i;
            cnt++;
        }
    }

    printf("%d\n", cnt);
}
