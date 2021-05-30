#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    char cur;
    int v[2] = {0, 0};

    cin >> s;
    cur = s[0];
    v[s[0] - '0']++;

    for (int i = 1; i < s.length(); i++)
    {
        if (cur != s[i])
        {
            cur = s[i];
            v[s[i] - '0']++;
        }
    }
    cout << min(v[0], v[1]);
}
