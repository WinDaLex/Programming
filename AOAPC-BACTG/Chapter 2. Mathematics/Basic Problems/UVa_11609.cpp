// UVa 11609
// Teams
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

const int MOD = 1000000007;

int T, N;

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);

        int ans = N, x = N - 1, y = 2;
        while (x) {
            if (x & 1) ans = (LL)ans * y % MOD;
            x >>= 1;
            y = (LL)y * y % MOD;
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
