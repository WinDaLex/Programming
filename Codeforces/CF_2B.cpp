// CF 2B
// The least round way
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1002;
const int INF = 1e6;

int N;
int A[MAXN][MAXN];

int factor[MAXN][MAXN][2];
int f[MAXN][MAXN][2];
enum dirt { UP, LEFT } from[MAXN][MAXN][2];

bool exist_zero;
int zero_x, zero_y;

int dp(int x, int y, int z) {
    int &res = f[x][y][z];
    if (res != -1) return res;
    if (A[x][y] == 0) return res = INF;

    if (dp(x - 1, y, z) < dp(x, y - 1, z)) {
        res = f[x - 1][y][z] + factor[x][y][z];
        from[x][y][z] = UP;
    } else {
        res = f[x][y - 1][z] + factor[x][y][z];
        from[x][y][z] = LEFT;
    }
    return res;
}

void print_path(int x, int y, int z) {
    if (x == 1 && y == 1) return;
    if (from[x][y][z] == UP) {
        print_path(x - 1, y, z);
        putchar('D');
    } else {
        print_path(x, y - 1, z);
        putchar('R');
    }
}

int main() {
    exist_zero = false;

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
            for (int x = A[i][j]; x && x % 2 == 0; x /= 2) factor[i][j][0]++;
            for (int x = A[i][j]; x && x % 5 == 0; x /= 5) factor[i][j][1]++;
            if (A[i][j] == 0) { exist_zero = true; zero_x = i; zero_y = j; }
        }
    }

    memset(f, -1, sizeof(f));
    for (int i = 1; i <= N; i++)
        f[0][i][0] = f[0][i][1] = f[i][0][0] = f[i][0][1] = INF;
    f[1][1][0] = factor[1][1][0];
    f[1][1][1] = factor[1][1][1];

    if (exist_zero && dp(N, N, 0) > 0 && dp(N, N, 1) > 0) {
        puts("1");
        for (int i = 0; i < zero_x - 1; i++) putchar('D');
        for (int i = 0; i < zero_y - 1; i++) putchar('R');
        for (int i = 0; i < N - zero_x; i++) putchar('D');
        for (int i = 0; i < N - zero_y; i++) putchar('R');
        putchar('\n');
    } else if (dp(N, N, 0) < dp(N, N, 1)) {
        printf("%d\n", dp(N, N, 0));
        print_path(N, N, 0);
        putchar('\n');
    } else {
        printf("%d\n", dp(N, N, 1));
        print_path(N, N, 1);
        putchar('\n');
    }

    return 0;
}
