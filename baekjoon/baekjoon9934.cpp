#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int depth;
vector<int> n;
vector<int> v[11];

void recur(int mid, int d)
{
    if(d == 0) return;
    
    v[d].push_back(n[mid]);
    
    int len = pow(2, d - 1) - 1;
    int left = mid - len / 2 - 1;
    int right = mid + len / 2 + 1;
    
    recur(left, d - 1);
    recur(right, d - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int temp;
    
    cin >> depth;
    
    for(int i = 0; i < pow(2, depth) - 1; i++)
    {
        cin >> temp;
        n.push_back(temp);
    }
    
    int mid = n.size() / 2;
    
    recur(mid, depth);
    
    for(int i = depth; i > 0; i--)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}

