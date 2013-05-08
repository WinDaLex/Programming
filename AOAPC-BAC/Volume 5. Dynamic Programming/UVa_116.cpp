// UVa 116
// Unidirectional TSP
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 12;
const int MAXN = 102;
const int INF = 1e9;

int M, N;
int A[MAXM][MAXN];

int f[MAXM][MAXN];
int prev[MAXM][MAXN];
int c[3];

int map(int x) { return (x - 1 + M) % M + 1; }

void dp(int x, int y) {
    c[0] = map(x - 1);
    c[1] = map(x);
    c[2] = map(x + 1);
    sort(c, c + 3);

    f[x][y] = INF;
    for (int i = 0; i < 3; i++)
        if (f[c[i]][y + 1] + A[x][y] < f[x][y])
            f[x][y] = f[prev[x][y] = c[i]][y + 1] + A[x][y];
}

void print_path(int last) {
    printf("%d", last);
    for (int i = 1; i < N; i++)
        printf(" %d", last = prev[last][i]);
    printf("\n");
}

int main() {
    while (scanf("%d%d", &M, &N) != EOF) {
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &A[i][j]);

        memset(f, 0, sizeof(f));
        for (int k = N; k >= 1; k--)
            for (int i = 1; i <= M; i++)
                dp(i, k);
    
        int ans = 1;
        for (int i = 1; i <= M; i++)
            if (f[i][1] < f[ans][1])
                ans = i;

        print_path(ans);
        printf("%d\n", f[ans][1]);
    }

    return 0;
}
