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

int n, m;
int u, v, w;
Graph<int> g;
int vis[MAXV];
bool exist_circle;

void Search(int x, int t);

int main() {
    int tot_case;
    scanf("%d", &tot_case);
    while (tot_case--) {
        scanf("%d%d", &n, &m);
        g.Init();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            g.AddEdge(u, v, w);
        }
        // Solve.
        for (int i = 0; i < n; ++i)
            vis[i] = INF;
        exist_circle = false;
        Search(0, 0);
        // Output.
        printf("%s\n", exist_circle ? "possible" : "not possible");
    }
    return 0;
}

void Search(int x, int t) {
    if (exist_circle || t >= vis[x])
        return;
    if (vis[x] != INF) {
        exist_circle = true;
        return;
    }
    int tmp = vis[x];
    vis[x] = t;
    for (int index = g.head[x];
        index != -1;
        index = g.edge[index].next)
    {
        Search(g.edge[index].v, t + g.edge[index].w);
    }
    vis[x] = tmp;
}
