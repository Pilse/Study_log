#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int a;
    int b;
};

bool cmp(node x, node y)
{
    return x.a < y.a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m;
        vector<node> v;
        cin >> m;
        int member = 0;
        for (int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end(), cmp);

        //        for(int j = 0; j < v.size() - 1; j++)
        //        {
        //            for(int k = j + 1; k < v.size(); k++)
        //            {
        //                if(v[j].b > v[k].b)
        //                {
        //                    member--;
        //                    break;
        //                }
        //            }
        //        }
        //        cout << member << '\n';
        int minNum = 100001;
        for (int j = 0; j < v.size(); j++)
        {
            if (minNum > v[j].b)
            {
                minNum = v[j].b;
                member++;
            }
        }

        cout << member << '\n';
    }
}
