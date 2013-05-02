// UVa 1424
// Salesmen
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 202;
const int MAXV = 102;
const int INF = 1e9;

int T, V, E, N;
int u, v;
int mat[MAXV][MAXV];
int work[MAXN];

int f[MAXN][MAXV];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &V, &E);   
        memset(mat, 0, sizeof(mat));
        for (int i = 1; i <= V; i++) mat[i][i] = 1;
        for (int i = 0; i < E; i++) {
            scanf("%d%d", &u, &v);
            mat[u][v] = mat[v][u] = 1;
        }

        scanf("%d", &N);
        for (int i = 1; i <= N; i++) 
            scanf("%d", &work[i]);
        
        for (int i = 1; i <= V; i++) f[0][i] = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= V; j++)
                f[i][j] = INF;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= V; j++)
                for (int k = 1; k <= V; k++)
                    if (mat[j][k])
                        f[i][j] = min(f[i - 1][k] + (work[i] == j ? 0 : 1), f[i][j]);
        
        int ans = INF;
        for (int i = 1; i <= V; i++)
            ans = min(f[N][i], ans);

        printf("%d\n", ans);
    }

    return 0;
}
