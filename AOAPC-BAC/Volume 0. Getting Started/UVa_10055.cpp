// UVa 10055
// Hashmat the Brave Warrior
// by A Code Rabbit

#include <cstdio>
typedef long long LL;

LL A, B;

int main() {
    while (scanf("%lld%lld", &A, &B) != EOF) {
        printf("%lld\n", A > B ? A - B : B - A);
    }

    return 0;
}
