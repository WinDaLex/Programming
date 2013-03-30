// UVaOJ 10305
// Ordering Tasks
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_N = 123;

int n, m;

bool graph[LIMITS_N][LIMITS_N];
int in_order[LIMITS_N];

bool is_finished[LIMITS_N];
int num_finished;

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        // INIT.
        memset(graph, false, sizeof(graph));
        memset(in_order, 0, sizeof(in_order));
        // Inputs.
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u][v] = true;
            ++in_order[v];
        }
        // Topo sort and outputs.
        memset(is_finished, false, sizeof(is_finished));
        num_finished = 0;
        bool is_first = true;
        while (num_finished < n) {
            for (int i = 1; i <= n; ++i) {
                if (!is_finished[i] && !in_order[i]) {
                    if (is_first) {
                        is_first = false;
                    } else {
                        printf(" ");
                    }
                    printf("%d", i);
                    is_finished[i] = true;
                    ++num_finished;
                    for (int j = 1; j <= n; ++j) {
                        if (graph[i][j]) {
                            --in_order[j];
                        }
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
