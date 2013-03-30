// UVaOJ 10305
// Ordering Tasks
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_N = 123;

int n, m;

bool graph[LIMITS_N][LIMITS_N];
/* the graph means direct precedence relations */

bool is_finished[LIMITS_N];

bool Check(int pos);

int main() {
    while (scanf("%d%d", &n, &m), n || m) {
        // INIT.
        memset(graph, false, sizeof(graph));
        memset(is_finished, false, sizeof(is_finished));
        // Inputs.
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u][v] = true;
        }      
        // Enumerate and outputs.
        bool is_first = true;
        int num_finished = 0;
        while (num_finished < n) {
            for (int i = 1; i <= n; ++i) {
                if (Check(i)) {
                    if (is_first) {
                        is_first = false;
                    } else {
                        printf(" ");
                    }
                    printf("%d", i);
                    is_finished[i] = true;
                    ++num_finished;
                }
            }
        }
        printf("\n");
    }

    return 0;
}

bool Check(int pos) {
    if (is_finished[pos]) {
        return false;
    }
    for (int i = 1; i <= n; ++i) {
        if (!is_finished[i] && graph[i][pos]) {
            return false;
        }
    }
    return true;
}
