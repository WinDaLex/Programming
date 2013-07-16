// UVa 10673
// Play with Floor and Ceil
// by A Code Rabbit

#include <cstdio>
#include <cmath>

int T, X, K;
int g, x, y;

void gcd(int a, int b, int &d, int &x, int &y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &X, &K);

        gcd(floor((double)X / K), ceil((double)X / K), g, x, y);

        printf("%d %d\n", x * X / g, y * X / g);
    }

    return 0;
}
