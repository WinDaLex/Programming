// UVa 11806
// Cheerleaders
// by A Code Rabbit

#include <cstdio>
#include <cmath>

const int MOD = 1000007;
const int MAXK = 502;
int C[MAXK][MAXK];

int T, M, N, K;

int main() {
    C[0][0] = 1;
    for (int i = 1; i < MAXK; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }

    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &M, &N, &K);

        int ans = 0;
        for (int s = 0; s < 16; s++) {
            int e = 0, r = M, c = N;

            if (s & 1) { r--; e++; }
            if (s & 2) { r--; e++; }
            if (s & 4) { c--; e++; }
            if (s & 8) { c--; e++; }
            
            ans = (ans + (int)pow(-1, e) * C[r * c][K] + MOD) % MOD;
        }
        
        printf("Case %d: %d\n", cas, ans);
    }

    return 0;
}
