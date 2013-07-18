// UVa 11889
// Benefit
// by A Code Rabbit

#include <cstdio>
#include <cmath>
#include <cstring>

typedef long long LL;

int T;
int A, C;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    scanf("%d", &T); 
    while (T--) {
        scanf("%d%d", &A, &C);

        if (C % A != 0) {
            puts("NO SOLUTION");
            continue;
        }

        int B;
        for (int i = 1; i <= A; i++) {
            B = C / A * i;
            if (gcd(A, B) == i)
                break;
        }

        printf("%d\n", B);
    }

    return 0;
}
