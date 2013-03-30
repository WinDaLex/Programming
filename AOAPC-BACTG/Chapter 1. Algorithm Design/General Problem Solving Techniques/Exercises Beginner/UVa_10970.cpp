// UVa 10970
// Big Chocolate
// by A Code Rabbit

#include <cstdio>

int M, N;

int main() {
    while (scanf("%d%d", &M, &N) != EOF) {
        printf("%d\n", (N - 1) + N * (M - 1));
    }

    return 0;
}
