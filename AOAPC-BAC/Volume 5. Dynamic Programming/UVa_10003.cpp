// UVa 10003
// Cutting Sticks
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 52;
const int INF = 1e9;

int L, N, C[MAXN];

int n;
int a[MAXN], sum[MAXN];
int f[MAXN][MAXN];

int dp(int x, int y) {
    if (x == y) return 0;

    int res = INF;
    for (int i = x; i <= y - 1; i++)
        res = min(f[x][i] + f[i + 1][y] + (sum[y] - sum[x - 1]), res);

    return res;
}

int main() {
    while (scanf("%d", &L) && L) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            scanf("%d", &C[i]);
        C[++N] = L;

        a[0] = C[0] = 0;
        for (int i = 1; i <= N; i++)
            a[i] = C[i] - C[i - 1];

        sum[0] = 0;
        for (int i = 1; i <= N; i++)
            sum[i] = sum[i - 1] + a[i];

        for (int k = 0; k < N; k++)
            for (int i = 1; i <= N; i++)
                if (i + k <= N) f[i][i + k] = dp(i, i + k);
    
        printf("The minimum cutting is %d.\n", f[1][N]);
    }

    return 0;
}
