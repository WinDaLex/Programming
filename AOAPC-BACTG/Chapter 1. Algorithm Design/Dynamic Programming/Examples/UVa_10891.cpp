// UVa 10891
// Game of Sum
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 102;

int N;
int a[MAXN];

int sum[MAXN];
int f[MAXN][MAXN];

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &a[i]);

        sum[0] = 0;
        for (int i = 1; i <= N; i++)
            sum[i] = sum[i - 1] + a[i];

        for (int k = 0; k < N; k++) {
            for (int i = 1; i + k <= N; i++) {
                f[i][i + k] = sum[i + k] - sum[i - 1];
                for (int j = i + 1; j <= i + k; j++)
                    f[i][i + k] = max(sum[i + k] - sum[i - 1] - f[j][i + k], f[i][i + k]);
                for (int j = i; j <= i + k - 1; j++)
                    f[i][i + k] = max(sum[i + k] - sum[i - 1] - f[i][j], f[i][i + k]);
            }
        }

        printf("%d\n", f[1][N] * 2 - sum[N]);
    }

    return 0;
}
