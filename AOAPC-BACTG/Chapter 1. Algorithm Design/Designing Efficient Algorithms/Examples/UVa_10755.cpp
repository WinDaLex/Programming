// UVa 10755
// Garbage Heap
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 22;
const LL INF = 1LL << 60;

int A, B, C;
LL a[MAXN][MAXN][MAXN];

LL s[MAXN][MAXN][MAXN];
LL ans;

LL compute(int x, int y, int z) {
    LL res = a[x][y][z];
    res += s[x - 1][y][z] + s[x][y - 1][z] + s[x][y][z - 1];
    res -= s[x - 1][y - 1][z] + s[x - 1][y][z - 1] + s[x][y - 1][z - 1];
    res += s[x - 1][y - 1][z - 1];
    return res;
}

LL sum(int x1, int x2, int y1, int y2, int z1, int z2) {
    LL res = s[x2][y2][z2];
    res -= s[x1 - 1][y2][z2] + s[x2][y1 - 1][z2] + s[x2][y2][z1 - 1];
    res += s[x1 - 1][y1 - 1][z2] + s[x1 - 1][y2][z1 - 1] + s[x2][y1 - 1][z1 - 1];
    res -= s[x1 - 1][y1 - 1][z1 - 1];
    return res;
}

void scan(int x1, int x2, int y1, int y2) {
    LL tmp = 0;
    for (int z = 1; z <= C; z++) {
        LL cur = sum(x1, x2, y1, y2, 1, z);
        ans = max(cur - tmp, ans);
        tmp = min(cur, tmp);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &A, &B, &C);
        for (int i = 1; i <= A; i++)
            for (int j = 1; j <= B; j++)
                for (int k = 1; k <= C; k++)
                    scanf("%lld", &a[i][j][k]);

        for (int x = 1; x <= A; x++)
            for (int y = 1; y <= B; y++)
                for (int z = 1; z <= C; z++)
                    s[x][y][z] = compute(x, y, z);

        ans = -INF;
        for (int x1 = 1; x1 <= A; x1++)
            for (int x2 = x1; x2 <= A; x2++)
                for (int y1 = 1; y1 <= B; y1++)
                    for (int y2 = y1; y2 <= B; y2++)
                        scan(x1, x2, y1, y2);

        printf("%lld\n", ans);
        printf("%s", T ? "\n" : "");
    }

    return 0;
}
