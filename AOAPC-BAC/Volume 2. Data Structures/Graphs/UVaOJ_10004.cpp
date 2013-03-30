// UVaOJ 10004
// Bicoloring
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LIMITS = 250;

bool graph[LIMITS][LIMITS];
int n, l;

bool is_red[LIMITS];
bool is_colored[LIMITS];

bool Search(int pos, bool color_red);

int main() {
    while (scanf("%d", &n), n) {
        scanf("%d", &l);
        // Inputs.
        memset(graph, false, sizeof(graph));
        for (int i = 0; i < l; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            graph[a][b] = true;
            graph[b][a] = true;
        }
        // DFS and outputs.
        memset(is_colored, false, sizeof(is_colored));
        printf("%s\n", Search(0, true) ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }

    return 0;
}

bool Search(int pos, bool color_red) {
    // Exit.
    if (is_colored[pos]) {
        if (is_red[pos] ^ color_red) {
            return false;
        } else {
            return true;
        }
    }
    // Continue.
    is_colored[pos] = true;
    is_red[pos] = color_red;
    bool result = true;
    for (int i = 0; i < n; ++i) {
        if (graph[pos][i]) {
            if (!Search(i, !color_red)) {
                result = false;
                break;
            }
        }
    }
    return  result;
}
