// HDU 4627
// The Unsolvable Problem
// by A Code Rabbit

#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

int T, N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(int a, int b) {
    return (LL)a / gcd(a, b) * b;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);

        LL ans;
        if (N == 2) {
            ans = 1;
        } else if (N % 2) {
            ans = lcm(N / 2, N / 2 + 1);
        } else {
            if (N / 2 % 2)
                ans = lcm(N / 2 - 2, N / 2 + 2);
            else
                ans = lcm(N / 2 - 1, N / 2 + 1);
        }

        cout << ans << endl;
    }
 
    return 0;
}
