// UVa 488
// Triangle Wave
// by A Code Rabbit

#include  <cstdio>

int N, M;

int main() {
    int T;
    scanf("%d", &T);
    bool first = true;
    while (T--) {
        scanf("%d%d", &N, &M);

        while (M--) {
            printf("%s", first ? first = false, "" : "\n");

            for (int i = 0; i < N; i++) {
                for (int j = 0; j <= i; j++)
                    printf("%d", i + 1);
                printf("\n");
            }
            for (int i = N - 2; i >= 0; i--) {
                for (int j = 0; j <= i; j++)
                    printf("%d", i + 1);
                printf("\n");
            }
        }
    }

    return 0;
}
