// UVa 11401
// Triangle Counting
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

const int MAXN = 1000002;

int N;

LL f[MAXN];

int main() {
    f[3] = 0;
    for (int i = 4; i < MAXN; i++)
        f[i] = f[i - 1] + ((LL)(i - 1) * (i - 2) / 2 - (i - 1) / 2) / 2;

    while (scanf("%d", &N) && N >= 3) {
        printf("%lld\n", f[N]);
    }

    return 0;
}
