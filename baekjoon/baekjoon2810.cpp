#include <iostream>

using namespace std;

int cup_holder[52];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int cnt = 0;
    int coupleFlag = 0;
    char c;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        //        cout<< c << '\n';
        switch (c)
        {
        case 'S':
            if (!cup_holder[i])
            {
                cup_holder[i] = 1;
                cnt++;
                //cout << 1;
            }
            else if (!cup_holder[i + 1])
            {
                cup_holder[i + 1] = 1;
                cnt++;
                //cout << 2;
            }
            break;
        case 'L':
            if (!coupleFlag)
            {
                coupleFlag = 1;
                if (!cup_holder[i])
                {
                    cup_holder[i] = 1;
                    cnt++;
                    //                        cout << 3;
                }
            }
            else
            {
                coupleFlag = 0;
                if (!cup_holder[i + 1])
                {
                    cup_holder[i + 1] = 1;
                    cnt++;
                    //                        cout << 4;
                }
            }
            break;
        default:
            break;
        }
    }

    cout << cnt << '\n';
}
