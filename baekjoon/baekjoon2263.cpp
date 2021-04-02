#include <iostream>
#include <vector>

using namespace std;
vector<int> in;
vector<int> post;

int n;

void pre(int inS, int inE, int postS, int postE)
{
    int inRoot{};
    if (postS <= postE)
    {
        cout << post[postE] << " ";

        for (int i = 0; i < n; i++)
        {
            if (in[i] == post[postE])
            {
                inRoot = i;
                break;
            }
        }

        pre(inS, inRoot - 1, postS, postS + (inRoot - 1 - inS));
        pre(inRoot + 1, inE, postS + (inRoot - inS), postE - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int t;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        in.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        post.push_back(t);
    }

    pre(0, n - 1, 0, n - 1);
    cout << '\n';
}
