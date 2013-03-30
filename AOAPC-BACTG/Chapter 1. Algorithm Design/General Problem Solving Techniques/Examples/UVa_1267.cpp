// UVa 1267
// Network
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1002;

int N;
int S, K;

vector<int> adj[MAXN], node[MAXN];
int p[MAXN];
bool vis[MAXN];

void search(int x, int parent, int level) {
    p[x] = parent;
    if (adj[x].size() == 1 && level > K) node[level].push_back(x);
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != parent)
            search(adj[x][i], x, level + 1);
}

void cover(int x, int parent, int level) {
    vis[x] = true;
    if (level == K) return;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != parent)
            cover(adj[x][i], x, level + 1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        scanf("%d%d", &S, &K);
        for (int i = 1; i <= N; i++) adj[i].clear();
        int u, v;
        for (int i = 0; i < N - 1; i++) {
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; i++) node[i].clear();
        search(S, 0, 0);
        for (int i = N - 1; i > K; i--) {
            for (int j = 0; j < node[i].size(); j++) {
                int cur = node[i][j];
                if (vis[cur]) continue;
                int pa = cur;
                for (int i = 0; i < K; i++) pa = p[pa];
                cover(pa, 0, 0);
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
