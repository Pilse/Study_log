#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int cnt;

void post(int s, int e)
{
    if (s <= e)
    {
        int i{}, first;
        first = v[s];

        for (i = s; i <= e; i++)
        {
            if (v[i] > first)
                break;
        }
        post(s + 1, i - 1);
        post(i, e);
        cout << first << '\n';
    }
}

int main()
{

    int n, c{};

    while (cin >> n)
    {
        c++;
        v.push_back(n);
    }

    post(0, c - 1);
}
