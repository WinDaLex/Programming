// CF 205A
// Domino
// by A Code Rabbit

#include <cstdio>

const int MAXN = 102;

int N;
int X[MAXN], Y[MAXN];

int sum_x, sum_y;

int main() {
    scanf("%d", &N);
    sum_x = sum_y = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        sum_x += X[i];
        sum_y += Y[i];
    }

    if (sum_x % 2 == 0 && sum_y % 2 == 0) {
        puts("0");
    } else if (sum_x % 2 == 1 && sum_y % 2 == 1) {
        bool bo = false;
        for (int i = 0; i < N; i++)
            if ((X[i] + Y[i]) % 2 == 1)
                bo = true;

        puts(bo ? "1" : "-1");
    } else {
        puts("-1");
    }

}
