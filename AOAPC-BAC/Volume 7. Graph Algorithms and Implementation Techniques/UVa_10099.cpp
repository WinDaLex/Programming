// UVaOJ 10099
// The Tourist Guide
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXV = 102;
const int MAXE = MAXV * MAXV;
const int INF = 1e9;

template <typename T>
struct Graph {
    T mat[MAXV][MAXV];
    void Init(int n) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = i == j ? INF : 0;
    }
    void AddEdge(int u, int v, T w) {
        mat[u][v] = w;
    }
};

namespace Dijkstra {
    bool vis[MAXV];
    template <typename T>
    void Go(T d[MAXV], T w[MAXV][MAXV], int n, int s) {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) d[i] = i == s ? INF : 0;
        for (int i = 0; i < n; i++) {
            T m = -1;
            int u;
            for (int j = 0; j < n; j++) if (!vis[j] && d[j] > m) m = d[u = j];
            vis[u] = true;
            for (int v = 0; v < n; v++) {
                m = min(d[u], w[u][v]);
                d[v] = m > d[v] ? m : d[v];
            }
        }
    }
}

int n, r;
int c1, c2, p;
int s, d, t;
Graph<int> graph;

int dis[MAXV];

int main() {
    int tot_case = 0;
    while (scanf("%d%d", &n, &r) && (n || r)) {
        // Input.
        graph.Init(n);
        for (int i = 0; i < r; i++) {
            scanf("%d%d%d", &c1, &c2, &p);
            graph.AddEdge(c1 - 1, c2 - 1, p);
            graph.AddEdge(c2 - 1, c1 - 1, p);
        }
        scanf("%d%d%d", &s, &d, &t);
        // Solve.
        Dijkstra::Go(dis, graph.mat, n, s - 1);
        // Output.
        printf("Scenario #%d\n", ++tot_case);
        printf("Minimum Number of Trips = %d\n", (t + dis[d - 1] - 2) / (dis[d - 1] - 1));
        printf("\n");
    }
    return 0;
}
