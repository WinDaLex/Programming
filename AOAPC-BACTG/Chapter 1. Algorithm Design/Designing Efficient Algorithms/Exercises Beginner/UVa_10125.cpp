// UVa 10125
// Sumsets
// by A Code Rabbit

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1002;

int N;
int a[MAXN];

void solve() {
    // 3SUM problem: Quadratic algorithm
    // Reference: http://en.wikipedia.org/wiki/3SUM
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int sum = a[i] - a[j];
            int l = 0, r = N - 1;
            while (l < r) {
                if (l == i || l == j) l++;
                if (r == i || r == j) r--;
                if (l >= r) break;
                if (a[l] + a[r] == sum) {
                    printf("%d\n", a[i]);
                    return;
                }
                if (a[l] + a[r] < sum) l++;
                else r--;
            }
        }
    }
    puts("no solution");
    return;
}

int main() {
    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        
        sort(a, a + N);

        solve();
    }

    return 0;
}
