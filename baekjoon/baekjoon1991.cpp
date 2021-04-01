#include <iostream>
#include <vector>

using namespace std;

vector<char> v[26];

void centerSearch(int n)
{
    char c = n + 'A';
    cout << c;

    if (v[n][0] != '.')
        centerSearch(v[n][0] - 'A');
    if (v[n][1] != '.')
        centerSearch(v[n][1] - 'A');
}
void leftSearch(int n)
{
    if (v[n][0] != '.')
        leftSearch(v[n][0] - 'A');

    char c = n + 'A';
    cout << c;

    if (v[n][1] != '.')
        leftSearch(v[n][1] - 'A');
}
void rightSearch(int n)
{
    if (v[n][0] != '.')
        rightSearch(v[n][0] - 'A');
    if (v[n][1] != '.')
        rightSearch(v[n][1] - 'A');

    char c = n + 'A';
    cout << c;
}

int main()
{
    int n;
    cin >> n;

    char a, b, c;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        v[a - 'A'].push_back(b);
        v[a - 'A'].push_back(c);
    }

    centerSearch(0);
    cout << '\n';
    leftSearch(0);
    cout << '\n';
    rightSearch(0);
    cout << '\n';
}
