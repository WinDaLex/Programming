// UVa 1510
// Neon Sign
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 1002;

int T, N;
int COL;

int sum[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);

        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                scanf("%d", &COL);
                sum[i] += COL;
                sum[j] += COL;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += sum[i] * (N - 1 - sum[i]);
        ans = N * (N - 1) * (N - 2) / 6 - ans / 2;
    
        printf("%d\n", ans);
    }

    return 0;
}
