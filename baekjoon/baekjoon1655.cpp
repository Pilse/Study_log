#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxh;
priority_queue<int, vector<int>, greater<int> > minh;

int main()
{
    int n;
    int input;
    int temp;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);

        if (i == 0)
        {
            maxh.push(input);
        }

        else if (maxh.size() == minh.size())
        {
            if (minh.top() < input)
            {
                temp = minh.top();
                minh.pop();
                minh.push(input);
                maxh.push(temp);
            }
            else
                maxh.push(input);
        }
        else if (maxh.size() > minh.size())
        {
            if (maxh.top() > input)
            {
                temp = maxh.top();
                maxh.pop();
                maxh.push(input);
                minh.push(temp);
            }
            else
                minh.push(input);
        }

        printf("%d\n", maxh.top());
    }
}
