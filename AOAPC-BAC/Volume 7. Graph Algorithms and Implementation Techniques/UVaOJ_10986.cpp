// UVaOJ 10986
// Sending email
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXV = 20002;
const int MAXE = 50002 * 2;
const int INF  = 2147483647;

template <typename T>
struct Edge {
    int v;
    T w;   
    int next;
};

template <typename T>
struct Graph {
    Edge<T> edge[MAXE];
    int tot_edge;
    int head[MAXV];
    void Init() {
        tot_edge = 0;
        memset(head, -1, sizeof(head));
    }
    void AddEdge(int u, int v, T w) {
        edge[tot_edge].v = v;
        edge[tot_edge].w = w;
        edge[tot_edge].next = head[u];
        head[u] = tot_edge;
        tot_edge++;
    }
};

namespace Dijkstra {
    bool vis[MAXV];
    template <typename T>
    void Go(T d[MAXV], Graph<T> g, int n, int s) {
        typedef pair<T, int> Node;
        priority_queue<Node, vector<Node>, greater<Node> > pq;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) { d[i] = i == s ? 0 : INF; }
        pq.push(make_pair(d[s], s));
        while (!pq.empty()) {
            Node m = pq.top();
            pq.pop();
            int u = m.second;
            if (vis[u]) continue;
            vis[u] = true;
            for (int e = g.head[u]; e != -1; e = g.edge[e].next) {
                int v = g.edge[e].v; int w = g.edge[e].w;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    pq.push(make_pair(d[v], v));
                }
            }
        }
    }
};

int n, m, s, t;
Graph<int> graph;

int dis[MAXV];

int main() {
    int tot_case;
    scanf("%d", &tot_case);
    for (int num_case = 0; num_case < tot_case; num_case++) {
        // Input.
        scanf("%d%d%d%d", &n, &m, &s, &t);
        graph.Init();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph.AddEdge(u, v, w);
            graph.AddEdge(v, u, w);
        };
        // Solve.
        Dijkstra::Go(dis, graph, n, s);
        // Output.
        printf("Case #%d: ", num_case + 1);
        if (dis[t] == INF) printf("unreachable\n");
        else printf("%d\n", dis[t]);
    }
    return 0;
}
