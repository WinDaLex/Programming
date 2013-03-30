// UVa 694
// The Collatz Sequence
// by A Code Rabbit

#include <cstdio>

int A, L;

int main() {
    int cas = 1;
    while (scanf("%d%d", &A, &L) && !(A == -1 && L == -1)) {
        long long num = A;
        int cnt_term = 1;
        while (num != 1) {
            if (num % 2) num = 3 * num + 1;
            else num /= 2;
            if (num > L) break;
            cnt_term++;
        }

        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
                cas++, A, L, cnt_term);
    }

    return 0;
}
