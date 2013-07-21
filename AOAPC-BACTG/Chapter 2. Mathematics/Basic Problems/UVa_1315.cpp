// 1315
// Crazy tea party
// by A Code Rabbit

#include <cstdio>

int T, N;

int sigma(int n) {
    return n * (n + 1) / 2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int left = N / 2, right = (N + 1) / 2;
        printf("%d\n", sigma(left - 1) + sigma(right - 1));
    }

    return 0;
}
