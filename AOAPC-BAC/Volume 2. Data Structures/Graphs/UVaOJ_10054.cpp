// UVaOJ 10054
// The Necklace
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS_COLORS = 100;
const int LIMITS_BEADS = 2000;

int num_case;

struct Beads {
    int u;
    int v;
};  

Beads beads[LIMITS_BEADS];
int graph[LIMITS_COLORS][LIMITS_COLORS];
int n;

int order[LIMITS_COLORS];

bool visit[LIMITS_COLORS];
int sum;

void Process(int u, int v);

bool MatchConditions();
void Search(int pos);

void Print(int x);

int main() {
    scanf("%d", &num_case);
    for (int t = 1; t <= num_case; ++t) {
        // INIT.
        memset(graph, 0, sizeof(graph));
        memset(order, 0, sizeof(order));
        memset(visit, false, sizeof(visit));
        sum = 0;
        // Inputs.
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int u, v;
            scanf("%d%d", &beads[i].u, &beads[i].v);
            Process(beads[i].u, beads[i].v);
        }
        // Compete the number of colors.
        int num_colors = 0;
        for (int i = 0; i < LIMITS_COLORS; ++i) {
            if (order[i]) {
                ++num_colors;
            }
        }
        // Judge whether the orders of them match conditions.
        bool exist_euler_circuit = MatchConditions();
        // Judge whether the undircected graph is connected.
        if (exist_euler_circuit) {
            for (int i = 0; i < LIMITS_COLORS; ++i) {
                if (order[i]) {
                    Search(i);
                    if (sum != num_colors) {
                        exist_euler_circuit = false;
                    }
                    break;
                }
            }
        }
        // Outputs.
        if (t > 1) {
            printf("\n");
        }
        printf("Case #%d\n", t);
        if (exist_euler_circuit) {
            Print(beads[0].u);
        } else {
            printf("some beads may be lost\n");
        }
    }

    return 0;
}

void Process(int u, int v) {
    ++graph[u][v];
    ++graph[v][u];
    ++order[u];
    ++order[v];
}
            
bool MatchConditions() {
    for (int i = 0; i < LIMITS_COLORS; ++i) {
        if (order[i] % 2) {
            return false;
        }
    }
    return true;
}

void Search(int pos) {
    visit[pos] = true;
    ++sum;
    for (int i = 0; i < LIMITS_COLORS; ++i) {
        if (graph[pos][i] && !visit[i]) {
            Search(i);
        }
    }
}

void Print(int x) {
    for (int i = 0; i < LIMITS_COLORS; ++i) {
        if (graph[x][i]) {
            --graph[x][i];
            --graph[i][x];
            Print(i);
            printf("%d %d\n", i, x);
        }
    }
}
