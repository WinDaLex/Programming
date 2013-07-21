// UVa 10791
// Minimum Sum LCM
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

int T, N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

LL min_sum(int x) {
    LL res = (LL)x + 1;
    for (int i = 2; i < sqrt(x); i++)
        if (x % i == 0 && lcm(i, x / i) == x)
            res = min(res, min((LL)x / i, min_sum(x / i)) + min((LL)i, min_sum(i)));
    return res;
}

int main() {
    while (scanf("%d", &N) && N) {
        printf("Case %d: %lld\n", ++T, min_sum(N));
    }

    return 0;
}
