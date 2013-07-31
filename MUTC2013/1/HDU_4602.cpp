// HDU 4602
// Partition
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

const int MOD = 1e9 + 7;

int T, N, K;

int power(int a, int n) {
    if (n == 0) return 1;
    int x = power(a, n / 2);
    int res = (LL)x * x % MOD;
    if (n % 2) res = (LL)res * a % MOD;
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
    
        int ans;
        if (K > N) ans = 0;
        else if (K == N) ans = 1;
        else if (K == N - 1) ans = 2;
        else ans = (LL)(N - K + 3) * power(2, N - K - 2) % MOD;

        printf("%d\n", ans);
    }

    return 0;
}
