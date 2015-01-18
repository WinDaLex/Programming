// Codeforces 286 B
// Mr. Kitayuta's Colorful Graph

#include <cstdio>
#include <cstring>

const int MAXN = 102;
const int MAXM = 102;

int N, M;
int A, B, C;
int Q;
int U, V;

int g[MAXM][MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &A, &B, &C);
        g[C][A][B] = g[C][B][A] = true;
    }

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            g[i][j][j] = true;
    
    for (int c = 1; c <= M; c++)
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    g[c][i][j] |= g[c][i][k] & g[c][k][j];

    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &U, &V);
        int ans = 0;
        for (int j = 1; j <= M; j++)
            if (g[j][U][V]) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
