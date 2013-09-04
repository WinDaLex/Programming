// UVa 1328
// Period
// by A Code Rabbit

#include <cstdio>

const int MAXN = 1000002;

int T, N;
char S[MAXN];

int f[MAXN];

int main() {
    while (scanf("%d", &N) == 1 && N) {
        scanf("%s", S);
        
        f[0] = f[1] = 0;
        for (int i = 1; i <= N; i++) {
            int j = f[i];
            while (j && S[j] != S[i]) j = f[j];
            f[i + 1] = S[i] == S[j] ? j + 1 : 0;
        }

        printf("Test case #%d\n", ++T);
        for (int i = 1; i <= N; i++)
            if (f[i] && i % (i - f[i]) == 0)
                printf("%d %d\n", i, i / (i - f[i]));
        printf("\n");
    }

    return 0;
}
