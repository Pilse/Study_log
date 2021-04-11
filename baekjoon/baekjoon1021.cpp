#include <iostream>

using namespace std;

int main()
{
    int n, m, num[50], deque[50], total = 0, pos = 0, count = 0;
    for (int i = 0; i < 50; i++)
        deque[i] = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        deque[i] = 0;
    for (int i = 0; i < m; i++)
        cin >> num[i];
    while (count < m)
    {
        int up = 0, down = 0;
        for (int i = pos; i != num[count] - 1; (++i) %= n)
        {
            if (deque[i] != -1)
                up++;
        }
        for (int i = pos; i != num[count] - 1; (--i) %= n)
        {
            if (deque[i] != -1)
                down++;
            if (i == 0)
                i = n;
        }
        total += min(up, down);
        //deque[num[count] - 1] = -1;
        for (pos = (num[count]) % n; deque[pos] == -1; (++pos) %= n)
        {
        }
        deque[num[count] - 1] = -1;
        count++;
    }
    cout << total;
}
