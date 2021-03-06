// UVa 1388
// Graveyard
// by A Code Rabbit

#include <cstdio>
#include <cmath>

int N, M;

int main() {
    while (scanf("%d%d", &N, &M) != EOF) {
        double ans = 0.0;
        for (int i = 0; i < N; i++) {
            double pos = (double)i / N * (N + M);
            ans += fabs(pos - round(pos));
        }

        printf("%.4lf\n", ans * 10000 / (N + M));
    }

    return 0;
}
