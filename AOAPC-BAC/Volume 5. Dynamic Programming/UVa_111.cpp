// UVa 111
// History Grading
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 22;

int N, C, R;

int a[MAXN], b[MAXN];
int f[MAXN][MAXN];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &C);
        a[C] = i;
    }

    while (scanf("%d", &R) != EOF) {
        b[R] = 1;
        for (int i = 2; i <= N; i++) {
            scanf("%d", &R);
            b[R] = i;
        }

        memset(f, 0, sizeof(f));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                f[i][j] = (a[i] == b[j] ? f[i - 1][j - 1] + 1 : max(f[i - 1][j], f[i][j - 1]));

        printf("%d\n", f[N][N]);
    }

    return 0;
}
