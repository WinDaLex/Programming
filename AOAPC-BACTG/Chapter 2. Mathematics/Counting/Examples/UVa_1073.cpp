// UVa 1073
// Glenbow Museum
// by A Code Rabbit

#include <cstdio>

typedef long long LL;

const int MAXN = 1002;

int N, T;
LL f[MAXN][5][2];

int main() {
    while (scanf("%d", &N) && N) {
        f[1][0][0] = f[2][1][0] = f[2][0][1] = 1;
        for (int i = 3; i <= N; i++) {
            for (int k = 0; k < 2; k++) {
                f[i][0][k] = f[i - 2][0][k];
                for (int j = 1; j < 5; j++)
                    f[i][j][k] = f[i - 2][j][k] + f[i - 1][j - 1][k];
            }
        }

        printf("Case %d: %lld\n", ++T, f[N][3][0] + f[N][4][1] + f[N - 1][4][0]);
    }

    return 0;
}
