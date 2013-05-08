// UVa 147
// Dollars
// by A Code Rabbit

#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 30002;
const int COIN[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

double R;

LL f[MAXN];

int main() {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < MAXN; j++)
            if (j >= COIN[i]) f[j] += f[j - COIN[i]];

    while (scanf("%lf", &R) && R) {
        printf("%6.2lf%17lld\n", R, f[(int)(R * 100 + 0.5)]);
    }

    return 0;
}
