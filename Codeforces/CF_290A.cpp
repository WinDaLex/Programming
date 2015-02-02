// Codeforces #290 A
// Fox And Snake

#include <cstdio>

int N, M;

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            for (int i = 0; i < M; i++) putchar('#');
        } else {
            if (i % 4 == 3) putchar('#');
            for (int i = 0; i < M - 1; i++) putchar('.');
            if (i % 4 == 1) putchar('#');
        }
        putchar('\n');
    }

    return 0;
}
