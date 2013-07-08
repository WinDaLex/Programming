// UVa 1292
// Strategic game
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1500;

int N, M, U, V;

vector<int> adj[MAXN];
bool vis[MAXN][2];
int f[MAXN][2];

int dp(int x, int y, int p) {
    if (vis[x][y]) return f[x][y];
    vis[x][y] = true;

    int &res = f[x][y];

    res = 1;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != p)
            res += dp(adj[x][i], 1, x);

    if (y) {
        int sum = 0;
        for (int i = 0; i < adj[x].size(); i++)
            if (adj[x][i] != p)
                sum += dp(adj[x][i], 0, x);
        res = min(res, sum);
    }

    return res;
}

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%d:(%d)", &U, &M);
            adj[U].clear();
            for (int j = 0; j < M; j++) {
                scanf("%d", &V);
                adj[U].push_back(V);
                adj[V].push_back(U);
            }
        }

        memset(vis, false, sizeof(vis));

        printf("%d\n", dp(0, 1, -1));
    }

    return 0;
}
