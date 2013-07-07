// UVa 590
// Always on the run
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 12;
const int MAXK = 1002;
const int MAXD = 32;
const int INF = 1e9;

int T, N, K;
int D[MAXN][MAXN];
int C[MAXN][MAXN][MAXD];

int f[MAXK][MAXN];

int dp(int x, int y) {
    int res = INF;
    for (int i = 1; i <= N; i++) {
        if (i != y) {
            int cost = C[i][y][(x - 1) % D[i][y]];
            if (cost != 0) res = min(res, f[x - 1][i] + cost);
        }
    }
    return res;
}

int main() {
    while (scanf("%d%d", &N, &K) != EOF && (N || K)) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i != j) {
                    scanf("%d", &D[i][j]);
                    for (int k = 0; k < D[i][j]; k++)
                        scanf("%d", &C[i][j][k]);
                }
            }
        }

        for (int i = 2; i <= N; i++)
            f[0][i] = INF;

        for (int i = 1; i <= K; i++)
            for (int j = 1; j <= N; j++)
                f[i][j] = dp(i, j);

        printf("Scenario #%d\n", ++T);
        if (f[K][N] != INF) printf("The best flight costs %d.\n", f[K][N]);
        else puts("No flight possible.");
        printf("\n");
    }

    return 0;
}
