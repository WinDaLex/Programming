// Edge Set
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

// Adjacent Matrix
template <typename T> 
struct Graph { 
    T mat[MAXV][MAXV]; 
    void Init(int n) { 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = i == j ? 0 : INF;
    }
    void AddEdge(int u, int v, T w) { 
        mat[u][v] = w; 
    } 
}; 

// Adjacent List
template <typename T> 
struct Edge { 
    int v; 
    T w;   
    int next; 
}; 

template <typename T> 
struct Graph { 
    Edge<T> edge[MAXE]; 
    int tot; 
    int head[MAXV]; 
    void init() { tot = 0; memset(head, -1, sizeof(head)); } 
    void add_edge(int u, int v, T w) { 
        edge[tot] = (Edge){v, w, head[u]}; 
        head[u] = tot++; 
    } 
};

// Kruskal
namespace Kruskal { 
    int p[MAXV]; 
    template <typename T> 
    int Cmp(Edge<T> a, Edge<T> b) { return a.w < b.w; } 
    int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); } 
    template <typename T>
    T Go(Edge<T> e[MAXE], int n, int m) {
        for (int i = 0; i < n; i++) p[i] = i;
        sort(e, e + m, Cmp<T>);
        T ans = 0;
        for (int i = 0; i < m; i++) {
            int u = Find(e[i].u); int v = Find(e[i].v);
            if (u != v) { ans += e[i].w; p[u] = v; }
        }
        return ans;
    }
}

// Prim
namespace Prim {
    bool vis[MAXV];
    template <typename T>
    T Go(T d[MAXV], T w[MAXV][MAXV], int n) {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) d[i] = i ? INF : 0;
        T ans = 0;
        for (int i = 0; i < n; i++) {
            T m = INF;
            int u;
            for (int j = 0; j < n; j++)
                if (!vis[j] && d[j] < m)
                    m = d[u = j]; 
            ans += d[u];
            vis[u] = true; 
            for (int v = 0; v < n; v++)
                if (d[u] + w[u][v] < d[v])
                    d[v] = d[u] + w[u][v];
        }
        return ans;
    }
}

// Dijkstra
namespace Dijkstra {
    bool vis[MAXV];
    template <typename T>
    void Go(T d[MAXV], T w[MAXV][MAXV], int n, int s) {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) d[i] = i == s ? 0 : INF;
        for (int i = 0; i < n; i++) {
            T m = INF;
            int u;
            for (int j = 0; j < n; j++)
                if (!vis[j] && d[j] < m) m = d[u = j]; 
            vis[u] = true;
            for (int v = 0; v < n; v++)
                if (d[u] + w[u][v] < d[v])
                    d[v] = d[u] + w[u][v];
        }
    }
}

// Dijkstra(Priority Queue)
namespace Dijkstra {
    bool vis[MAXV];
    template <typename T>
    void Go(T d[MAXV], Graph<T> g, int n, int s) {
        typedef pair<T, int> Node;
        priority_queue<Node, vector<Node>, greater<Node> > pque;
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) { d[i] = i == s ? 0 : INF; }
        pque.push(make_pair(d[s], s));
        while (!pque.empty()) {
            Node m = pque.top();
            pque.pop();
            int u = m.second;
            if (vis[u]) continue;
            vis[u] = true;
            for (int e = g.head[u]; e != -1; e = g.edge[e].next) {
                int v = g.edge[e].v; int w = g.edge[e].w;
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    pque.push(make_pair(d[v], v));
                }
            }
        }
    }
};

// Bellman Ford
namespace BellmanFord {
    template <typename T>
    void Go(Edge<T> e[MAXE], int n, int m, T d[MAXV], int s) {
        for (int i = 0; i < n; i++) d[i] = i == s ? INF : 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int u = e[j].u; int v = e[j].v; int w = e[j].w;
                if (d[u] + w < d[v])
                    d[v] = d[u] + w;
            }
        }
    }
}

// Bellman Ford(FIFO queue)

// Floyd
namespace Floyd { 
    template <typename T> 
    void Go(T w[MAXV][MAXV], int n) { 
        for (int k = 0; k < n; k++) 
            for (int i = 0; i < n; i++) 
                for (int j = 0; j < n; j++) 
                    if (w[i][k] + w[k][j] < w[i][j]) 
                        w[i][j] = w[i][k] + w[k][j]; 
    } 
}
