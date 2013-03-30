// UVa 10905
// Children's Game
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 52;
const int LEN = 1002;

int N;
char num[MAXN][LEN]; 

int cmp(const char *a, const char *b) {
    char tmp_a[LEN], tmp_b[LEN];
    strcpy(tmp_a, a);
    strcpy(tmp_b, b);
    return strcmp(strcat(tmp_a, tmp_b), strcat(tmp_b, tmp_a));
}

int main() {
    while (scanf("%d", &N) && N) {
        getchar();
        for (int i = 0; i < N; i++)
            scanf("%s", num[i]);

        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j < N - i - 1; j++)
                if (cmp(num[j], num[j + 1]) < 0)
                    swap(num[j], num[j + 1]);

        for (int i = 0; i < N; i++)
            printf("%s", num[i]);
        printf("\n");
    }

    return 0;
}
