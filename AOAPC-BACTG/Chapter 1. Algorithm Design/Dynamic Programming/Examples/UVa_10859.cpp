// UVa 10859
// Placing Lampposts
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1002;
const int C = 2000;

int T, N, M;
int u, v;

vector<int> adj[MAXN];
bool vis[MAXN][2];
int f[MAXN][2];

int dp(int x, int y, int p) {
    if (vis[x][y]) return f[x][y];
    vis[x][y] = true;

    int res = C;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != p)
            res += dp(adj[x][i], 1, x);
    if (!y && p >= 0) return f[x][y] = res + 1;

    int res2 = 0;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != p)
            res2 += dp(adj[x][i], 0, x);
    if (p >= 0) res2++;

    return f[x][y] = min(res, res2);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < M; i++) {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(vis, false, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < N; i++)
            if (!vis[i][0])
                ans += dp(i, 0, -1);

        printf("%d %d %d\n", ans / C, M - ans % C, ans % C);
    }

    return 0;
}
