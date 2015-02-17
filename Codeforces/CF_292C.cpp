// Codeforces #292 C
// Drazil and Factorial

#include <cstdio>

const int MAXN = 17;

int N;
char A[MAXN];

int prime[4] = {2, 3, 5, 7};
int factor[4][10] = {
    {0, 0, 1, 0, 2, 0, 1, 0, 3, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 2},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
};

int cnt[4];

void putnchar(char ch, int num) {
    while (num--) putchar(ch);
}

int main() {
    scanf("%d", &N);
    scanf("%s", A);

    for (int i = 0; i < N; i++) {
        int d = A[i] - '0';
        for (int j = 2; j <= d; j++)
            for (int k = 0; k < 4; k++)
                cnt[k] += factor[k][j];
    }

    putnchar('7', cnt[3]);
    putnchar('5', cnt[2] - cnt[3]);
    putnchar('3', cnt[1] - cnt[2] - cnt[3]);
    putnchar('2', cnt[0] - cnt[1] - cnt[2] * 2);
    putnchar('\n', 1);

    return 0;
}
