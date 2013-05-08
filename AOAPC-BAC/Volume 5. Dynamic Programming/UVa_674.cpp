// UVa 674
// Coin Change
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 7491;
const int COIN[5] = {50, 25, 10, 5, 1};

int N;

int f[MAXN];

int main() {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < MAXN; j++)
            if (j >= COIN[i]) f[j] += f[j - COIN[i]];

    while (scanf("%d", &N) != EOF) {
        printf("%d\n", f[N]);
    }

    return 0;
}
