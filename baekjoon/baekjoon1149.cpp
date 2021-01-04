#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int R, G, B;

    cin >> N;
    cin >> R >> G >> B;

    for (int i = 0; i < N-1; i++)
    {
        int temp1, temp2, temp3;
        int R1, G1, B1;
        cin >> temp1 >> temp2 >> temp3;
        R1 = temp1 + min(G, B);
        G1 = temp2 + min(R, B);
        B1 = temp3 + min(R, G);
        R = R1; G = G1; B = B1;
    }

    int result = min({ R, G, B });
    cout << result;


}