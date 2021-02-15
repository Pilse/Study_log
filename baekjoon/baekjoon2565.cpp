#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[550];
int stor[550];
int idx = 1;
vector<pair<int, int> > v;

bool compare(pair<int, int> n, pair<int, int> m)
{
    return n.first < m.first;
}

int main()
{
    int N;
    int temp1, temp2;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> temp1 >> temp2;
        v.push_back(make_pair(temp1, temp2));
    }
    ::sort(v.begin(), v.end(), compare);

    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            dp[1] = 1;
            stor[idx] = v[i - 1].second;
        }
        else
        {
            if (v[i - 1].second > stor[idx])
            {
                idx++;
                stor[idx] = v[i - 1].second;
            }
            else
            {
                for (int j = 1; j <= idx; j++)
                {
                    if (v[i - 1].second < stor[j])
                    {
                        stor[j] = v[i - 1].second;
                        dp[i] = j;
                    }
                }
            }
        }
        cout << idx << endl;
    }
    cout << idx << endl;
}
//8 2 9 1 4 6 7 10
