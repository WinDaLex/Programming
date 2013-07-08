// UVa 1452
// Jump
// by A Code Rabbit

#include <cstdio>

const int MAXN = 500002;

int T, N, K;

int f[MAXN], g[MAXN], h[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);

        f[1] = 0;
        f[2] = (f[1] + K) % 2;
        f[3] = (f[2] + K) % 3;

        g[2] = 1 - f[2];
        g[3] = (g[2] + K) % 3;

        h[3] = 3 - f[3] - g[3];

        for (int i = 4; i <= N; i++) {
            f[i] = (f[i - 1] + K) % i;
            g[i] = (g[i - 1] + K) % i;
            h[i] = (h[i - 1] + K) % i;
        }

        printf("%d %d %d\n", h[N] + 1, g[N] + 1, f[N] + 1);
    }

    return 0;
}
