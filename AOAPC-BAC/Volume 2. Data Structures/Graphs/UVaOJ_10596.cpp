// UVaOJ 10596
// Morning Walk
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_N = 250;
const int LIMITS_R = 10086;

int graph[LIMITS_N][LIMITS_N];
int n, r;

int order[LIMITS_N];

bool visit[LIMITS_R];
int sum;

void Process(int u, int v);
bool MatchConditions();
void Search(int pos);

int main() {
    while (scanf("%d%d", &n, &r) != EOF) {
        // INIT.
        memset(graph, 0, sizeof(graph));
        memset(order, 0, sizeof(order));
        memset(visit, false, sizeof(visit));
        sum = 0;
        // Inputs.
        for (int i = 0; i < r; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            Process(u, v);
        }
        // Judge whether the orders match conditions.
        bool is_euler_circuit = MatchConditions();
        // Judge whether the undirected graph is connected.
        if (is_euler_circuit) {
            Search(0);
            if (sum != n) {
                is_euler_circuit = false;
            }
        }
        // Outputs.
        printf("%s\n", is_euler_circuit ? "Possible" : "Not Possible");
    }

    return 0;
}

void Process(int u, int v) {
    ++order[u];
    ++order[v];
    ++graph[u][v];
    ++graph[v][u];
}

bool MatchConditions() {
    for (int i = 0; i < n; ++i) {
        if (order[i] % 2) {
            return false;
        }
    }
    return true;
}

void Search(int pos) {
    visit[pos] = true;
    ++sum;
    for (int i = 0; i < n; ++i) {
        if (graph[pos][i] && !visit[i]) {
            Search(i);
        }
    }
}
