// UVaOJ 10034
// Freckles
// by A Code Rabbit

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXV = 102;
const int MAXE = MAXV * MAXV;

template <typename T>
struct Point {
    T x, y;
    static double GetDistance(Point a, Point b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
}; 

template <typename T>
struct Edge {
    int u, v;
    T w;
};

template <typename T>
struct Graph{
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

int n;
Point<double> point[MAXV];
Graph<double> graph;

int main() {
    int tot_case;
    scanf("%d", &tot_case);
    for (int t = 0; t < tot_case; t++) {
        // Input.
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &point[i].x, &point[i].y);
        // Compute each the length of edges.
        graph.Init();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                double w = Point<double>::GetDistance(point[i], point[j]);
                graph.AddEdge(i, j, w);
            }
        }
        // Output.
        printf("%s", t ? "\n" : "");
        printf("%.2lf\n", Kruskal::Go(graph.edge, n, graph.tot_edge));
    }
    return 0;
}
