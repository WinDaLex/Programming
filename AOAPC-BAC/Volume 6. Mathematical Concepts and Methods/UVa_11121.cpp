// UVa 11121
// Base -2
// by A Code Rabbit

#include <cstdio>

int T, N;

const int MAXD = 34;

int b[MAXD];

void convert(int n) {
    if (n == 0) {
        puts("0");
        return;
    }

    int c;
    for (c = 0; n; c++) {
        b[c] = (n % 2 + 2) % 2;
        n = (n - b[c]) / (-2);
    }

    while (c--)
        printf("%d", b[c]);
    printf("\n");
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &N);
        printf("Case #%d: ", cas);
        convert(N);
    }

    return 0;
}
