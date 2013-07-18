/// UVa 10943
// How do you add?
// by A Code Rabbit

#include <cstdio>

const int MOD = 1000000;

const int MAXN = 202;
const int MAXK = 202;

int N, K;

int com[MAXN][MAXK];

int C(int n, int k) {
    if (com[n][k]) return com[n][k];
    if (n == k || k == 0) return com[n][k] = 1;
    return com[n][k] = (C(n - 1, k) + C(n - 1, k - 1)) % MOD;
}

int main() {
    while (scanf("%d%d", &N, &K) && (N || K)) {
        printf("%d\n", C(N + K - 1, K - 1));
    }

    return 0;
}
