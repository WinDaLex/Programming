// UVa 11464
// Even Parity
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 17;
const int INF = 1000000000;

int N;
int grid[MAXN][MAXN];

int cur[MAXN][MAXN];

int check(int x) {
    memset(cur, 0, sizeof(cur));
    for (int i = 1; i <= N; i++)
        if (x & (1 << (i - 1))) cur[1][i] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cur[i][j] = cur[i - 1][j - 1] ^ cur[i - 2][j] ^ cur[i - 1][j + 1];

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!cur[i][j] && grid[i][j]) return INF;
            if (cur[i][j] != grid[i][j]) res++;
        }
    }

    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &grid[i][j]);

        int ans = INF;
        for (int i = 0; i < (1 << N); i++) {
            int ret = check(i);
            ans = min(ans, ret);
        }

        printf("Case %d: %d\n", cas, ans == INF ? -1 : ans);
    }

    return 0;
}
