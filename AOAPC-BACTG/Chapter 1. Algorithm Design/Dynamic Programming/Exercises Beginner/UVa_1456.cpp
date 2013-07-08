// UVa 1456
// Cellular Network
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXN = 102;
const int MAXW = 102;
const int INF = 1e9;

int T, N, W;
int U[MAXN];

int sum[MAXN];
int f[MAXW][MAXN];

int dp(int x, int y) {
    int res = INF;
    for (int i = 0; i < y; i++)
        res = min(res, f[x - 1][i] + y * (sum[y] - sum[i]));
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &W);
        for (int i = 1; i <= N; i++)
            scanf("%d", &U[i]);

        sort(U + 1, U + N + 1, greater<int>());

        sum[0] = 0;
        for (int i = 1; i <= N; i++)
            sum[i] = sum[i - 1] + U[i];

        for (int i = 1; i <= W; i++)
            f[i][0] = INF;
        for (int i = 1; i <= N; i++)
            f[0][i] = INF;
        f[0][0] = 0;

        for (int i = 1; i <= W; i++)
            for (int j = 1; j <= N; j++)
                f[i][j] = dp(i, j);

        printf("%.4lf\n", (double)f[W][N] / sum[N]);
    }

    return 0;
}
