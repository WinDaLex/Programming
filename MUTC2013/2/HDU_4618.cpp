// HDU 4618
// Palindrome Sub-Array
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 302;
const int MAXM = 302;

int T, N, M;
int A[MAXN][MAXM];

bool equal(int a, int b, int c, int d) {
    return a == b && b == c && c == d;
}

bool check(int x, int y, int p) {
    if (x + p > N || y + p > M) return false;
    while (p > 0) {
        for (int i = 0; i <= p / 2; i++) {
            if (!equal(A[x + i][y], A[x + p - 1 - i][y], A[x + i][y + p - 1], A[x + p - 1 - i][y + p - 1]))
                return false;
            if (!equal(A[x][y + i], A[x][y + p - 1 - i], A[x + p - 1][y + i], A[x + p - 1][y + p - 1 - i]))
                return false;
        }
        x++; y++;
        p -= 2;
    }
    return true;
}

int solve() {
    for (int p = min(N, M); p >= 1; p--)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (check(i, j, p))
                    return p;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &A[i][j]);

        printf("%d\n", solve());
    }

    return 0;
}
