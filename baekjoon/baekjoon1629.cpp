#include <iostream>

using namespace std;

long long modular(int A, int B, int C)
{
    if(B == 0)
        return 1;
    else if (B == 1)
        return A%C;

    long long temp = modular(A, B/2, C) % C;

    if(B%2==0)
        return (A%C * A%C)%C;
    else
        return ((A%C*A%C)%C*A)%C;
}

int main()
{
    int A, B, C;
    int result = 1;

    cin >> A >> B >> C;

    result = modular(A, B, C);

    cout << result << endl;
}