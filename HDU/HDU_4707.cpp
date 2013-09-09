// HDU 4707
// Pet
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100002;

int T, N, D, U, V;

vector<int> adj[MAXN];

int dfs(int x, int p, int d) {
    if (!d) return 1;

    int ret = 1;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != p)
            ret += dfs(adj[x][i], x, d - 1);
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &D);
        for (int i = 0; i < N; i++)
            adj[i].clear();
        for (int i = 0; i < N - 1; i++) {
            scanf("%d%d", &U, &V);
            adj[U].push_back(V);
            adj[V].push_back(U);
        }

        printf("%d\n", N - dfs(0, -1, D));
    }

    return 0;
}
