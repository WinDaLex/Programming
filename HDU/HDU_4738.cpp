// HDU 4738
// Caocao's Bridges
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1002;
const int MAXM = 1000002;
const int INF = 10002;

int N, M, U, V, W;

int g[MAXN][MAXN];
int pre[MAXN];
int dfs_clock, ans;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    for (int v = 1; v <= N; v++) {
        if (g[u][v] == -1) continue;
        if (!pre[v]) {
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv > pre[u]) ans = min(ans, g[u][v]);
        } else if (v != fa) {
            lowu = min(lowu, pre[v]);
        }
    }
    return lowu;
}

int main() {
    while (scanf("%d%d", &N, &M) == 2 && (N || M)) {
        memset(g, -1, sizeof(g));
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &U, &V, &W);
            if (g[U][V] == -1) g[U][V] = g[V][U] = W;
            else g[U][V] = g[V][U] = INF;
        }

        memset(pre, 0, sizeof(pre));
        dfs_clock = 0;
        ans = INF;

        dfs(1, -1);

        ans = ans == INF ? -1 : ans;
        ans = ans == 0 ? 1 : ans;
        ans = dfs_clock != N ? 0 : ans;
        printf("%d\n", ans);
    }

    return 0;
}
