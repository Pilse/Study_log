#include <iostream>
#include <unordered_map>

using namespace std;

struct meta
{
    string parent;
    int cnt;
};

int union_network(string x, string y, unordered_map<string, meta> &network);
string find_parent(string x, unordered_map<string, meta> &network);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unordered_map<string, meta> network;

        while (n--)
        {
            string f1, f2;
            cin >> f1 >> f2;

            if (network.find(f1) == network.end())
                network[f1] = {f1, 1};
            if (network.find(f2) == network.end())
                network[f2] = {f2, 1};

            cout << union_network(f1, f2, network) << '\n';
        }
    }
}

int union_network(string x, string y, unordered_map<string, meta> &network)
{
    string px = find_parent(x, network);
    string py = find_parent(y, network);

    if (px == py)
        return network[px].cnt;

    if (px > py)
        swap(px, py);
    network[py].parent = px;

    network[px].cnt += network[py].cnt;

    return network[px].cnt;
}

string find_parent(string x, unordered_map<string, meta> &network)
{
    if (x == network[x].parent)
        return x;

    return find_parent(network[x].parent, network);
}
