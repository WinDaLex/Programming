// UVa 10564
// Paths through the Hourglass
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 22;
const int MAXS = 502;

int N, S;
int A[MAXN][MAXN], B[MAXN][MAXN];

LL f1[MAXN][MAXN][MAXS];
LL f2[MAXN][MAXN][MAXS];

int p1[MAXN][MAXN][MAXS];
int p2[MAXN][MAXN][MAXS];

void dp1(int x, int y, int z) {
    f1[x][y][z] = (x == N ? (z == B[x][y] ? 1 : 0) : f1[x + 1][y][z - B[x][y]] + f1[x + 1][y + 1][z - B[x][y]]);
    p1[x][y][z] = (x == N ? -1 : (f1[x + 1][y][z - B[x][y]] > 0 ? y : y + 1));
}

void dp2(int x, int y, int z) {
    f2[x][y][z] = (x == N ? f1[1][1][z] : f2[x + 1][y - 1][z - A[x][y]] + f2[x + 1][y][z - A[x][y]]);
    p2[x][y][z] = (x == N ? -1 : f2[x + 1][y - 1][z - A[x][y]] > 0 ? y - 1 : y);
}

void print_path2(int x, int y, int z) {
    if (x == N) return;
    putchar(p1[x][y][z] == y ? 'L' : 'R');
    print_path2(x + 1, p1[x][y][z], z - B[x][y]);
}

void print_path1(int x, int y, int z) {
    if (x == N) {
        print_path2(1, 1, z);
        return;
    }
    if (x == 1) printf("%d ", y - 1);
    putchar(p2[x][y][z] == y - 1 ? 'L' : 'R');
    print_path1(x + 1, p2[x][y][z], z - A[x][y]);
}

int main() {
    while (scanf("%d%d", &N, &S) && (N || S)) {
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N + 1 - i; j++)
                scanf("%d", &A[i][j]);

        memset(B, 0, sizeof(B));
        B[1][1] = A[N][1];
        for (int i = 2; i <= N; i++)
            for (int j = 1; j <= i; j++)
                scanf("%d", &B[i][j]);

        memset(f1, 0, sizeof(f1));
        for (int i = N; i >= 1; i--)
            for (int j = 1; j <= i; j++)
                for (int k = 0; k <= S; k++)
                    dp1(i, j, k);

        memset(f2, 0, sizeof(f2));
        for (int i = N; i >= 1; i--)
            for (int j = 1; j <= N + 1 - i; j++)
                for (int k = 0; k <= S; k++)
                    dp2(i, j, k);

        LL ans = 0;
        for (int i = 1; i <= N; i++)
            ans += f2[1][i][S];

        printf("%lld\n", ans);
        for (int i = 1; i <= N; i++) {
            if (f2[1][i][S]) {
                print_path1(1, i, S);
                break;
            }
        }
        puts("");
    }

    return 0;
}
