// UVa 558
// Wormholes
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXV = 1002;
const int MAXE = 2002;
const int INF = 1e9;

template <typename T>
struct Edge {
    int u, v;
    T w;
};

template <typename T>
struct Graph {
    Edge<T> edge[MAXE];
    int tot_edge;
    void Init() { tot_edge = 0; }
    void AddEdge(int u, int v, T w) {
        edge[tot_edge].u = u;
        edge[tot_edge].v = v;
        edge[tot_edge].w = w;
        tot_edge++;
    }
};

namespace BellmanFord {
    template <typename T>
    void Go(Edge<T> e[MAXE], int n, int m, T d[MAXV], int s, bool& exist_circle) {
        for (int i = 0; i < n; i++) d[i] = i == s ? INF : 0;
        for (int i = 0; i < n; i++) {
            bool bo = true;
            for (int j = 0; j < m; j++) {
                int u = e[j].u; int v = e[j].v;
                if (d[u] + e[j].w < d[v]) {
                    d[v] = d[u] + e[j].w;
                    bo = false;
                }
            }
            if (bo) return;
        }
        exist_circle = true;
    }
}

int n, m;
Graph<int> graph;
bool exist_circle;
int dis[MAXV];

int main() {
    int tot_case;
    scanf("%d", &tot_case);
    while (tot_case--) {
        // Input.
        scanf("%d%d", &n, &m);
        graph.Init();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph.AddEdge(u, v, w);
        }
        // Solve.
        exist_circle = false;
        BellmanFord::Go(graph.edge, n, m, dis, 0, exist_circle);
        // Output. 
        printf("%s\n", exist_circle ? "possible" : "not possible");
    }
    return 0;
}
