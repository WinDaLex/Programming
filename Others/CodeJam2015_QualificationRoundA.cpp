// Google Code Jam 2015 Qualification Round A
// Standing Ovation

#include <cstdio>
#include <cctype>

int T, S, K;

int getn() {
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    return ch - '0';
}

int main() {
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &S);
        int ans = 0, sum = 0;
        for (int i = 0; i <= S; i++) {
            if (sum < i) {
                ans += i - sum;
                sum = i;
            }
            K = getn();
            sum += K;
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
