// UVa 1366
// Martian Mining
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 502;
const int MAXM = 502;
const int INF = 1e9;

int N, M;
int A[MAXN][MAXM], B[MAXN][MAXM];

int sum1[MAXN][MAXM], sum2[MAXN][MAXM];
int f[MAXN][MAXM];

int dp(int x, int y) {
    return max(f[x - 1][y] + sum1[x][y], f[x][y - 1] + sum2[x][y]);
}

int main() {
    while (scanf("%d%d", &N, &M) != EOF && (N || M)) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &A[i][j]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d", &B[i][j]);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                sum1[i][j] = sum1[i][j - 1] + A[i][j];
                sum2[i][j] = sum2[i - 1][j] + B[i][j];
            }
        }

    
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                f[i][j] = dp(i, j);
    
        printf("%d\n", f[N][M]);
    }

    return 0;
}
