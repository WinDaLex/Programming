// UVa 10300
// Ecological Premium
// by A Code Rabbit

#include <cstdio>

int F;
int A, B, C;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &F);

        int ans = 0;
        for (int i = 0; i < F; i++) {
            scanf("%d%d%d", &A, &B, &C);
            ans += A * C;
        }

        printf("%d\n", ans);
    } 

    return 0;
}
