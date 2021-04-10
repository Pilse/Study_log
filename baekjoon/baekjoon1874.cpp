#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<char> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, j = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        for (; j <= t; j++)
        {
            st.push(j);
            v.push_back('+');
        }
        if (st.size() == 0)
        {
            cout << "NO" << '\n';
            return 0;
        }

        while (st.top() != t)
        {
            st.pop();
            v.push_back('-');

            if (st.size() == 0)
            {
                cout << "NO" << '\n';
                return 0;
            }
        }

        st.pop();
        v.push_back('-');
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}
