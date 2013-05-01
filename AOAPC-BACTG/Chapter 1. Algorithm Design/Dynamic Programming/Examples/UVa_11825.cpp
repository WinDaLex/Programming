// UVa 11825
// Hacker's Crackdown
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 18;

int T, N, M, node;
int p[MAXN];

int c[1 << MAXN];
int f[1 << MAXN];

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &M);
            p[i] = 1 << i;
            for (int j = 0; j < M; j++) {
                scanf("%d", &node);
                p[i] |= (1 << node);
            }
        }

        for (int i = 0; i < (1 << N); i++) {
            c[i] = 0;
            for (int j = 0; j < N; j++)
                if (i & (1 << j))
                    c[i] |= p[j];
        }

        int all = (1 << N) - 1;
        for (int i = 0; i < (1 << N); i++) {
            f[i] = 0;
            for (int j = i; j; j = (j - 1) & i)
                if (c[j] == all) f[i] = max(f[i ^ j] + 1, f[i]);
        }

        printf("Case %d: %d\n", ++T, f[all]);
    }

    return 0;
}
