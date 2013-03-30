// UVaOJ 567
// Risk
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int N = 20;
const int MAXV = 22;
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
                    if (w[i][k] + w[k][j] < w[i][j])
                        w[i][j] = w[i][k] + w[k][j];
    }
}

int n;
int a, b;
Graph<int> graph;

void Read(int x, int num);

int main() {
    int tot_case = 0;
    while (scanf("%d", &n) != EOF) {
        // Input.
        graph.Init(N);
        Read(0, n);
        for (int i = 1; i < N - 1; i++) {
            scanf("%d", &n);
            Read(i, n);
        }
        // Solve.
        Floyd::Go(graph.mat, N);
        // Output.
        printf("Test Set #%d\n", ++tot_case);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            printf("%2d to %2d: %d\n", a, b, graph.mat[a - 1][b - 1]);
        }
        printf("\n");
    }
    return 0;
}

void Read(int x, int num) {
    for (int i = 0; i < num; i++) {
        int y;
        scanf("%d", &y);
        graph.AddEdge(x, y - 1, 1);
        graph.AddEdge(y - 1, x, 1);
    }
}
