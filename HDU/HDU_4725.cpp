// HDU 4725
// The Shortest Path in Nya Graph
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int v, w;
    bool operator<(edge rhs) const {
        return w > rhs.w;
    }
};

const int MAXN = 100002;
const int MAXM = 100002;
const int INF = 1e9;

int T, N, M, C, U, V, W;
int L[MAXN];
vector<int> layer_node[MAXN];

bool done[MAXN];
bool vis[MAXN];

vector<edge> adj[MAXN];
int d[MAXN];
priority_queue<edge> pq;

void add_layer(int u, int l) {
    if (l < 1 || l > N || vis[l]) return;
    vis[l] = true;
    for (int i = 0; i < layer_node[l].size(); i++) {
        int v = layer_node[l][i];
        if (!done[v] && d[u] + C < d[v]) {
            d[v] = d[u] + C;
            pq.push((edge){v, d[v]});
        }
    }
}

void dijstra() {
    memset(done, false, sizeof(done));
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= N; i++) d[i] = (i == 1 ? 0 : INF);
    while (!pq.empty()) pq.pop();

    pq.push((edge){1, 0});
    while (!pq.empty()) {
        int u = pq.top().v, w = pq.top().w;
        //printf("u = %d, w = %d\n", u, w);
        pq.pop();

        if (done[u]) continue;
        done[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, w = adj[u][i].w;
            if (!done[v] && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                pq.push((edge){v, d[v]});
            }
        }

        add_layer(u, L[u] - 1);
        add_layer(u, L[u] + 1);
    }
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &N, &M, &C);
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            layer_node[i].clear();
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &L[i]);
            layer_node[L[i]].push_back(i);
        }
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &U, &V, &W);
            adj[U].push_back((edge){V, W});
            adj[V].push_back((edge){U, W});
        }

        dijstra();

        printf("Case #%d: %d\n", cas, d[N] == INF ? -1 : d[N]);
    }

    return 0;
}
