// UVa 11728
// Alternate Task
// by A Code Rabbit

#include <cstdio>

int T, S;

int sum(int x) {
    int res = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res += i;
            if (i != x / i) res += x / i;
        }
    }

    return res;
}

int main() {
    while (scanf("%d", &S) && S) {
        int ans = -1;
        for (int i = S; i >= 1; i--) {
            if (sum(i) == S) {
                ans = i;
                break;
            }
        }

        printf("Case %d: %d\n", ++T, ans);
    }

    return 0;
}
