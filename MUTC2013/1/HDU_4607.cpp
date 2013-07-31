// HDU 4607
// Park Visit
// by A Code Rabbit

#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100002;

int T, N, M, K;
vector<int> adj[MAXN];

int pa[MAXN];
int ans;

void dfs(int x, int p) {
    pa[x] = p;
    for (int i = 0; i < adj[x].size(); i++)
        if (adj[x][i] != p)
            dfs(adj[x][i], x);
}

int dp(int x) {
    int max1 = 0, max2 = 0;
    for (int i = 0; i < adj[x].size(); i++) {
        if (adj[x][i] != pa[x]) {
            int tmp = dp(adj[x][i]);
            if (tmp > max1) {
                max2 = max1;
                max1 = tmp;
            } else if (tmp > max2) {
                max2 = tmp;
            }
        }
    }
    ans = max(ans, max1 + max2 + 1);
    return max1 + 1;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);

        for (int i = 1; i <= N; i++)
            adj[i].clear();

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        ans = 0;
        dp(1);
        ans--;

        for (int i = 0; i < M; i++) {
            scanf("%d", &K);
            K--;
            if (K <= ans) {
                printf("%d\n", K);
            } else {
                printf("%d\n", ans + (K - ans) * 2);
            }
        }
    }

    return 0;
}
