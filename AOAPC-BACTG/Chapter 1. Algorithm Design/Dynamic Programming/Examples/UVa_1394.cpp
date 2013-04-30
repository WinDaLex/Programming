// UVa 1394
// And Then There Was One
// by A Code Rabbit

#include <cstdio>

const int MAXN = 10002;

int N, K, M;

int f[MAXN];

int main() {
    while (scanf("%d%d%d", &N, &K, &M) && (N || K || M)) {
        f[1] = 0;
        for (int i = 2; i <= N; i++)
            f[i] = (f[i - 1] + K) % i;
        int ans = (M - K + 1 + f[N]) % N;

        printf("%d\n", (ans + N - 1) % N + 1);
    }

    return 0;
}
