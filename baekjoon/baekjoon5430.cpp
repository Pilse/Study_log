#include <iostream>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string str;
        int num;
        string arr;
        string temp;
        int j = 0;
        int flag = 1;
        deque<int> dq;

        cin >> str;
        cin >> num;
        cin >> arr;

        for (int i = 1; i < arr.length(); i++)
        {
            if (arr[i] == ',' || arr[i] == ']')
            {
                temp[j] = arr[i];
                if (j != 0)
                    dq.push_back(stoi(temp));

                j = 0;
            }
            else
                temp[j++] = arr[i];
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'R')
                flag = (flag + 1) % 2;
            if (str[i] == 'D')
            {
                if (dq.empty())
                {
                    cout << "error" << '\n';
                    break;
                }
                if (flag)
                    dq.pop_front();
                else
                    dq.pop_back();
            }

            if (i == str.length() - 1)
            {
                int s = dq.size();
                cout << "[";
                for (int l = 0; l < s; l++)
                {
                    if (flag)
                    {
                        cout << dq.front();
                        if (j != dq.size() - 1)
                            cout << ",";
                        dq.pop_front();
                    }
                    else
                    {
                        cout << dq.back();
                        if (j != dq.size() - 1)
                            cout << ",";
                        dq.pop_back();
                    }
                }
                cout << "]" << '\n';
            }
        }
    }
}
