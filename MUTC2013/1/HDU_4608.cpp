// HDU 4608
// I-number
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 100002;

int T, N;
char X[MAXN];

int sum_digit() {
    int res = 0;
    for (int i = 0; i < N; i++)
        res += X[i] - '0';
    return res;
}

void plus_plus() {
    int i = N - 1;
    X[i]++;
    while (i >= 0 && X[i] > '9') {
        X[i--] = '0';
        if (i < 0) {
            for (int j = N; j >= 0; j--)
                X[j + 1] = X[j];
            X[0] = '1';
            N++;
        } else {
            X[i]++;
        }
    }
}

int main() {
    scanf("%d", &T);
    getchar();

    while (T--) {
        gets(X);
        N = strlen(X);

        do {
            plus_plus();
        } while (sum_digit() % 10 != 0);

        puts(X);
    }

    return 0;
}
