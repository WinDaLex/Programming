// UVa 1099
// Sharing Chocolate
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 17;
const int MAXM = 102;

int T, N, X, Y;
int A[MAXN];

int tot[1 << MAXN];
int f[1 << MAXN][MAXM];

int cnt_one(int x) { return x == 0 ? 0 : cnt_one(x >> 1) + (x & 1); }

int dp(int s, int x) {
    if (f[s][x] != -1) return f[s][x];

    int &res = f[s][x];
    if (cnt_one(s) == 1) return res = 1;

    int y = tot[s] / x;
    for (int s0 = (s - 1) & s; s0; s0 = (s0 - 1) & s) {
        int s1 = s - s0;
        if (tot[s0] % x == 0 && dp(s0, min(x, tot[s0] / x)) && dp(s1, min(x, tot[s1] / x)))
            return res = 1;
        if (tot[s0] % y == 0 && dp(s0, min(y, tot[s0] / y)) && dp(s1, min(y, tot[s1] / y)))
            return res = 1;
    }
    return res = 0;
}

int main() {
    while (scanf("%d", &N) && N) {
        scanf("%d%d", &X, &Y);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        memset(tot, 0, sizeof(tot));
        for (int i = 0; i < (1 << N); i++)
            for (int j = 0; j < N; j++)
                if (i & (1 << j))
                    tot[i] += A[j];

        memset(f, -1, sizeof(f));
        int all = (1 << N) - 1;
        int ans = (tot[all] != X * Y ? 0 : dp(all, min(X, Y)));
        printf("Case %d: %s\n", ++T, ans ? "Yes" : "No");
    }

    return 0;
}
