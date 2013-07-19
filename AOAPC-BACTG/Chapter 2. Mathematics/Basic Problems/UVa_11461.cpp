// UVa 11461
// Square Numbers
// by A Code Rabbit

#include <cstdio>
#include <cmath>

int A, B;

int main() {
    while (scanf("%d%d", &A, &B) && (A || B)) {
        printf("%d\n", (int)sqrt(B) - (int)sqrt(A - 1));
    }

    return 0;
}
