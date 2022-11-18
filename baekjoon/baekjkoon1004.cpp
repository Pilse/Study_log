#include <iostream>
#include <cmath>

using namespace std;

bool is_included(int x1, int y1, int x2, int y2, int r2);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        int cnt = 0;
        
        while(n--)
        {
            int x, y, r;
            cin >> x >> y >> r;
            
            if(is_included(x1, y1, x, y, r) ^ is_included(x2, y2, x, y, r))
                cnt++;
        }
        cout << cnt << '\n';
    }
}

bool is_included(int x1, int y1, int x2, int y2, int r2)
{
    int diff_x = x1 - x2;
    int diff_y = y1 - y2;
    double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
    return (double)r2 > distance;
}
