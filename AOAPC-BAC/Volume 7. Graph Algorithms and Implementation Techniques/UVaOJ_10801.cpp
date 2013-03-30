// UVaOJ 10801
// Lift Hopping
// by A Code Rabbit

#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN = 7;
const int MAXK = 102;
const int MAXV = MAXN * MAXK;
const int INF = 1e9;

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

namespace Dijkstra {
    bool vis[MAXV];
    template <typename T>
    void Go(T d[MAXV], T w[MAXV][MAXV], int n) {
        memset(vis, false, sizeof(vis));
        //for (int i = 0; i < n; i++) d[i] = i == s ? 0 : INF;
        for (int i = 0; i < n; i++) {
            T m = INF;
            int u;
            for (int j = 0; j < n; j++) if (!vis[j] && d[j] < m) m = d[u = j]; 
            vis[u] = true; 
            for (int v = 0; v < n; v++)
                if (d[u] + w[u][v] < d[v])
                    d[v] = d[u] + w[u][v];
        }
    }
}

int n, k;
int t[MAXN];
Graph<int> graph;
bool exist[MAXN][MAXK];
int num_vertex;
int dis[MAXV];   

int GetPos(int x, int y);
void Insert(int x, int y);

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        // Input.
        for (int i = 0; i < n; i++)
            scanf("%d", &t[i]);
        memset(exist, false, sizeof(exist));
        int index_floor;
        int index_elevator = 0;
        char ch;
        while (index_elevator < n) {
            scanf("%d%c", &index_floor, &ch);
            exist[index_elevator][index_floor] = true;
            if (ch == '\n') index_elevator++;
        }
        // Modeling.
        num_vertex = n * MAXK;
        graph.Init(num_vertex);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < MAXK; j++)
                if (exist[i][j])
                    Insert(i, j);
        // Dijkstra.
        for (int i = 0; i < num_vertex; i++)
            dis[i] = (i % MAXK == 0) && exist[i / MAXK][0] ? 0 : INF;
        Dijkstra::Go(dis, graph.mat, num_vertex);
        // Find the minimum.
        int ans = INF;
        for (int i = 0; i < n; i++) {
            int val = dis[GetPos(i, k)];
            ans = val < ans ? val : ans;
        }
        // Output.
        if (ans == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}

int GetPos(int x, int y) {
    return x * MAXK + y;
}

void Insert(int x, int y) {
    int pos1 = GetPos(x, y);
    int pos2;
    for (int i = 0; i < n; i++) {
        if (i != x && exist[i][y]) {
            pos2 = GetPos(i, y);
            graph.AddEdge(pos1, pos2, 60);
        }
    }
    for (int i = 0; i < MAXK; i++) {
        if (i != y && exist[x][i]) {
            pos2 = GetPos(x, i);
            graph.AddEdge(pos1, pos2, t[x] * std::abs(y - i));
        }
    }
}
