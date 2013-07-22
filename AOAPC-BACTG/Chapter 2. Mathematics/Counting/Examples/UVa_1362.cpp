// UVa 1362
// Exploring Pyramids
// by A Code Rabbit

#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 302;
const int MOD = 1e9;

char S[MAXN];

int f[MAXN][MAXN];

int dp(int i, int j) {
    if (i == j) return 1;
    if (S[i] != S[j]) return 0;
    if (f[i][j] >= 0) return f[i][j];

    int res = 0;
    for (int k = i + 1; k <= j; k++)
        if (S[i] == S[k])
            res = (res + (LL)dp(i + 1, k - 1) * dp(k, j)) % MOD;
    return f[i][j] = res;
}

int main() {
    while (gets(S)) {
        memset(f, -1, sizeof(f));
        printf("%d\n", dp(0, strlen(S) - 1));
    }

    return 0;
}
