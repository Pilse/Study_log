#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    deque<char> dq;

    int n, k;

    cin >> n >> k;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        while (k && !dq.empty() && dq.back() < str[i])
        {
            k--;
            dq.pop_back();
        }
        dq.push_back(str[i]);
    }
    while (k)
    {
        dq.pop_back();
        k--;
    }

    int len = dq.size();
    for (int i = 0; i < len; i++)
    {
        cout << dq.front();
        dq.pop_front();
    }

    cout << '\n';
}
