// UVa 1513
// Movie collection
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 100002;
const int MAXM = 100002;

struct Bit {
    int c[MAXN + MAXM], n;

    void init(int n) { memset(c, 0, sizeof(c)); this->n = n; }
    
    void add(int x, int y) {
        for (int i = x; i <= n; i += i & -i)
            c[i] += y;
    }

    int sum(int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= i & -i)
            ret += c[i];
        return ret;
    }
};

int T, N, M;
int A[MAXN];

Bit bit;
int no[MAXN];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);

        bit.init(N + M);

        for (int i = 1; i <= N; i++) {
            bit.add(i, 1);
            no[i] = N + 1 - i;
        }

        for (int i = 1; i <= M; i++) {
            scanf("%d", &A[i]);
            printf("%d%c", N - bit.sum(no[A[i]]), i < M ? ' ' : '\n');

            bit.add(no[A[i]], -1);
            no[A[i]] = N + i;
            bit.add(no[A[i]], 1);
        }
    }

    return 0;
}
