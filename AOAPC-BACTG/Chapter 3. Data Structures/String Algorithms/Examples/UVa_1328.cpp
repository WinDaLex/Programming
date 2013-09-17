// UVa 1328
// Period
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 1000002;

namespace kmp {
    void get_fail(char* p, int* f) {
        int m = strlen(p);
        f[0] = f[1] = 0;
        for (int i = 1; i < m; i++) {
            int j = f[i];
            while (j && p[i] != p[j]) j = f[j];
            f[i + 1] = p[i] == p[j] ? j + 1 : 0;
        }
    }
}

int T, N;
char S[MAXN];

int f[MAXN];

int main() {
    while (scanf("%d", &N) == 1 && N) {
        scanf("%s", S);

        kmp::get_fail(S, f);

        printf("Test case #%d\n", ++T);
        for (int i = 1; i <= N; i++)
            if (f[i] && i % (i - f[i]) == 0)
                printf("%d %d\n", i, i / (i - f[i]));
        printf("\n");
    }

    return 0;
}
