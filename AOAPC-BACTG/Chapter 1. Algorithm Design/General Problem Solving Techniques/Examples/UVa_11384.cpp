// UVa 11384
// Help is needed for Dexter
// by A Code Rabbit

#include <cstdio>
#include <cmath>

#define lg(x) (log(x)/log(2))

int N;

int main() {
    while (scanf("%d", &N) != EOF) {
        printf("%d\n", (int)lg(N) + 1);
    }

    return 0;
}
