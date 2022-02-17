#include <iostream>

using namespace std;

void input();
void gcd(long long a, long long b);
long long get_digit(long long a, long long b);

long long A, B;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    
    gcd(A, B);
}

void input() {
    cin >> A >> B;
}

void gcd(long long a, long long b) {
    long long digit = get_digit(a, b);
    
    for(long long i = 1; i <= digit; i++) {
        cout << 1;
    }
}

long long get_digit(long long a, long long b) {
    long long c;
    
    while(b != 0) {
        c = a % b;
        
        a = b;
        
        b = c;
    }
    
    return a;
}
