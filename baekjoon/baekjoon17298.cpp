#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;

    int n;
    cin >> n;

    int *arr1 = new int[n];
    int *arr2 = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    arr2[n - 1] = -1;
    s.push(arr1[n - 1]);

    int temp;

    for (int i = n - 2; i >= 0; i--)
    {
        temp = s.top();
        while (arr1[i] >= temp)
        {
            s.pop();
            if (s.size() > 0)
                temp = s.top();
            else
                break;
        }
        if (s.size() == 0)
            arr2[i] = -1;
        else
            arr2[i] = temp;
        s.push(arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << '\n';
}
