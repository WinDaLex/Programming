// HDU 4642
// Fliping game
// by A Code Rabbit

#include <cstdio>

const int MAXN = 102;
const int MAXM = 102;

int T, N, M;
int A[MAXN][MAXM];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &A[i][j]);

        puts(A[N - 1][M - 1] ? "Alice" : "Bob");
    }

    return 0;
}
