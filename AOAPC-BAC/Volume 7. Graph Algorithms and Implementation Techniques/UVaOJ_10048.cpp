// UVaOJ 10048
// Audiophobia
// by A Code Rabbit

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXV = 102;
const int INF = 1e9;

template <typename T>
struct Graph {
    T mat[MAXV][MAXV];
    void Init(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = i == j ? 0 : INF;
            }
        }
    }
    void AddEdge(int u, int v, T w) {
        mat[u][v] = w;
    }
};

namespace Floyd {
    template <typename T>
    void Go(T w[MAXV][MAXV], int n) {
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (max(w[i][k], w[k][j]) < w[i][j])
                        w[i][j] = max(w[i][k], w[k][j]);
    }
}

int c, s, q;
Graph<int> graph;

int main() {
    int tot_case = 0;
    while (scanf("%d%d%d", &c, &s, &q) && (c || s || q)) {
        // Input.
        graph.Init(c);
        for (int i = 0; i < s; i++) {
            int c1, c2, d;
            scanf("%d%d%d", &c1, &c2, &d);
            c1--, c2--;
            graph.AddEdge(c1, c2, d);
            graph.AddEdge(c2, c1, d);
        }
        // Solve.
        Floyd::Go(graph.mat, c);
        // Output.
        printf("%s", tot_case ? "\n" : "");
        printf("Case #%d\n", ++tot_case);
        for (int i = 0; i < q; i++) {
            int c1, c2, d;
            scanf("%d%d", &c1, &c2);
            c1--, c2--;
            if (graph.mat[c1][c2] != INF) {
                printf("%d\n", graph.mat[c1][c2]);
            } else {
                printf("no path\n");
            }
        }
    }
    return 0;
}
