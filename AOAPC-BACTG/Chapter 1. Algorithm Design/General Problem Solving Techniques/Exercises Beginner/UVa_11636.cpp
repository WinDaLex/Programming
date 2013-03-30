// UVa 11636
// Hello World!
// by A Code Rabbit

#include <cstdio>
#include <cmath>

#define lg(x) (log(x)/log(2))

int N;

int main() {
    int cas = 1;
    while (scanf("%d", &N) && N > 0) {
        printf("Case %d: %d\n", cas++, N == 1 ? 0 : (int)lg(N - 1) + 1);
    } 

    return 0;
}
