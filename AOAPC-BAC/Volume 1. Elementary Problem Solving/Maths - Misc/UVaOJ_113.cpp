// UVaOJ 113
// Power of Cryptography 
// by A Code Rabbit

#include <cstdio>
#include <cmath>

double n, p;

int main() {
    while (scanf("%lf%lf", &n, &p) != EOF) {
        printf("%d\n", (int)(pow(p, 1 / n) + 0.5));
    }

    return 0;
}

