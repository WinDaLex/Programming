// CF 206A
// Vasya and Digital Root
// by A Code Rabbit

#include <cstdio>

int K, D;

int main() {
    scanf("%d%d", &K, &D);
    if (D == 0) {
        puts(K == 1 ? "0" : "No solution");
    } else {
        if (K == 1) {
            printf("%d\n", D);
        } else {
            putchar('1');
            for (int i = 0; i < K - 2; i++)
                putchar('0');
            printf("%d\n", D - 1);
        }
    }

    return 0;
}
