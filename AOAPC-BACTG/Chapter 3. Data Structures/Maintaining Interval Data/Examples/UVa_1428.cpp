// UVa 1428
// Ping pong
// by A Code Rabbit

#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 20002;
const int MAXA = 100002;

struct Bit {
    int c[MAXA], n;
    void init(int x) { memset(c, 0, sizeof(c)); n = x; }
    void add(int x, int y) {
        while (x <= n) { c[x] += y; x += x & -x; }
    }
    int sum(int x) {
        int ret = 0;
        while (x > 0) { ret += c[x]; x -= x & -x; }
        return ret;
    }
};

int T, N;
int A[MAXN];

Bit bit;
int c[MAXN], d[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
    
        bit.init(1e5);
        for (int i = 1; i <= N; i++) {
            c[i] = bit.sum(A[i] - 1);
            bit.add(A[i], 1);
        }

        bit.init(1e5);
        for (int i = N; i >= 1; i--) {
            d[i] = bit.sum(A[i] - 1);
            bit.add(A[i], 1);
        }

        LL ans = 0;
        for (int i = 1; i <= N; i++)
            ans += c[i] * (N - i - d[i]) + (i - 1 - c[i]) * d[i];

        printf("%lld\n", ans);
    }

    return 0;
}
