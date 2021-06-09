#include <iostream>
#include <algorithm>

using namespace std;

int o[101];
int m[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int cnt = 0;
    int tot = 0;
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
        cin >> o[i];

    for (int i = 1; i <= k; i++)
    {
        int least = -1;
        int flag = 0;
        for (int j = 0; j < cnt; j++)
        {
            if (m[j] == o[i])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            if (cnt != n)
                m[cnt++] = o[i];
            else
            {
                //                cout << i << " ";
                int idx;
                for (int w = 0; w < cnt; w++)
                {
                    int d = distance(&o[i], find(&o[i], o + k + 1, m[w]));
                    //                    cout << d;
                    if (d > least)
                    {
                        least = d;
                        idx = w;
                    }
                }
                //                cout << idx << '\n';
                m[idx] = o[i];
                tot++;
            }
        }
    }
    cout << tot << '\n';
}
