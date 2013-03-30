// UVaOJ 10055
// Hashmat the brave warrior
// by A Code Rabbit

#include <cstdio>

long long a, b;

int main() {
    while (scanf("%lld%lld", &a, &b) != EOF) {
        printf("%lld\n", a > b ? a - b : b - a);
    }

    return 0;
}
