// UVa 12086
// Potentiometers
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 200002;

struct Bit {
    int c[MAXN], n;

    void init(int n) {memset(c, 0, sizeof(c)); this->n = n; }

    void add(int x, int v) {
        for (int i = x; i <= n; i += i & -i)
            c[i] += v;
    }

    int sum(int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= i & -i)
            ret += c[i];
        return ret;
    }
};

int T, N, X, Y;
int A[MAXN];
char S[20];

Bit bit;

int main() {
    while (scanf("%d", &N) == 1 && N) {
        bit.init(N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
            bit.add(i, A[i]);
        }

        printf("%s", T++ ? "\n" : "");
        printf("Case %d:\n", T);

        while (scanf("%s", S) == 1 && S[0] != 'E') {
            scanf("%d%d", &X, &Y);
            if (S[0] == 'M') {
                printf("%d\n", bit.sum(Y) - bit.sum(X - 1));
            } else if (S[0] == 'S') {
                bit.add(X, Y - A[X]);
                A[X] = Y;
            }
        }
    }

    return 0;
}
