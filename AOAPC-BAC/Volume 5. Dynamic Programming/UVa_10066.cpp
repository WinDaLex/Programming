// UVa 10066
// The Twin Towers
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;

int T, N1, N2;
int A1[MAXN], A2[MAXN];

int f[MAXN][MAXN];

int main() {
    while (scanf("%d%d", &N1, &N2) && (N1 || N2)) {
        for (int i = 1; i <= N1; i++) scanf("%d", &A1[i]);
        for (int i = 1; i <= N2; i++) scanf("%d", &A2[i]);

        memset(f, 0, sizeof(f));
        for (int i = 1; i <= N1; i++)
            for (int j = 1; j <= N2; j++)
                f[i][j] = (A1[i] == A2[j] ? f[i - 1][j - 1] + 1 : max(f[i - 1][j], f[i][j - 1]));

        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", ++T, f[N1][N2]);
    }

    return 0;
}
