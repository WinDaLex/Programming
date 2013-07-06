// UVa 607
// Scheduling Lectures
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1002;
const int INF = 1 << 30;

int K, N, L, C;
int T[MAXN];

int f[MAXN][MAXN];
bool vis[MAXN][MAXN];

int di(int t) {
    if (t == 0) return 0;
    if (1 <= t && t <= 10) return -C;
    return (t - 10) * (t - 10);
}

int dp(int x, int y) {
    int &res = f[x][y];
    if (vis[x][y]) return res;
    vis[x][y] = true;

    if (x == 0) return y == 0 ? res = 0 : res = INF;

    res = INF;
    for (int i = y, sum = 0; i > 0; i--) {
        if ((sum += T[i]) > L) break;
        res = min(res, dp(x - 1, i - 1) + di(L - sum));
    }

    return res;
}

int main() {
    while (scanf("%d", &N) != EOF && N) {
        scanf("%d%d", &L, &C);
        for (int i = 1; i <= N; i++)
            scanf("%d", &T[i]);

        int ans = 1, cur = 0;
        for (int i = 1; i <= N; i++) {
            if ((cur += T[i]) > L) {
                cur = T[i];
                ans++;
            }
        }

        memset(vis, false, sizeof(vis));

        printf("%s", K ? "\n" : "");
        printf("Case %d:\n", ++K);
        printf("Minimum number of lectures: %d\n", ans);
        printf("Total dissatisfaction index: %d\n", dp(ans, N));
    }

    return 0;
}
