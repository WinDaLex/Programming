// UVa 11038
// How Many O's?
// by A Code Rabbit

#include <cstdio>
#include <cmath>

const int MAXD = 12;

typedef long long LL;

LL M, N;

unsigned f[MAXD], g[MAXD];

int count_zero(unsigned x) {
    int res = 0;
    do {
        if (x % 10 == 0) res++;
        x /= 10;
    } while (x);
    return res;
}

unsigned total(unsigned x) {
    if (x < 0) return 0;
    if (x == 0) return 1;

    unsigned res = 0, digit = 0;
    while (x) {
        res += count_zero(x) * pow(10, digit) + f[digit];
        while (x % 10 == 0) {
            x /= 10;
            digit++;
        }
        x--;
    }
    res += g[digit];

    return res;
}

int main() {
    f[0] = 0;
    for (int i = 1; i < 10; i++)
        f[i] = f[i - 1] * 10 + pow(10, i - 1);

    for (int i = 0; i < 10; i++)
        g[i] = total(pow(10, i) - 1);

    while (scanf("%lld%lld", &M, &N) && (M >= 0)) {
        printf("%u\n", total(N) - total(M - 1));
    }

    return 0;
}
