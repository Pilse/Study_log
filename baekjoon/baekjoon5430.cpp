#include <iostream>
#include <queue>
#include <string>
#include <stack>

using namespace std;

queue<int> q;

void reverseQueue()
{
    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n;
    string str;
    string num;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        cin >> n;
        cin >> num;

        int flag = 0;

        for (int i = 1; i < num.length(); i += 2)
        {
            q.push(num[i] - '0');
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'R')
                reverseQueue();
            else if (str[i] == 'D')
            {
                if (q.size() == 0)
                {
                    flag = 1;
                    cout << "error"
                         << "\n";
                    break;
                }
                else
                    q.pop();
            }
        }
        if (!flag)
        {
            cout << "[";
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                cout << q.front();
                if (i != qSize - 1)
                    cout << ",";
                q.pop();
            }
            cout << "]"
                 << "\n";
        }
    }
}
