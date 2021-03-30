#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string fac{};
    int n, k;

    cin >> n >> k;
    cin >> fac;

    int cnt = 0;

    for (int i = 0; i < fac.length(); i++)
    {
        int flag = 0;
        if (fac[i] == 'P')
        {
            for (int j = k; j >= 0; j--)
            {
                if (i - j >= 0)
                {
                    if (fac[i - j] == 'H')
                    {
                        fac[i - j] = 'N';
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
            {
                cnt++;
                continue;
            }
            for (int j = k; j >= 0; j--)
            {
                if (i + j <= n - 1)
                {
                    if (fac[i + j] == 'H')
                    {
                        fac[i + j] = 'N';
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}