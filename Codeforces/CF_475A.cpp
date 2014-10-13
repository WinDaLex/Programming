#include <cstdio>

int K;

int main() {
    scanf("%d", &K);

    printf("+------------------------+\n");
    for (int i = 0; i < 3; i++) {
        if (i == 2) printf("|%c.......................|\n", K < 3 ? '#' : 'O');
        printf("|");
        for (int j = 0; j < 11; j++) {
            int num = j * 3 + i;
            num = (num < 2 ? num : num + 1);
            printf("%c.", num < K ? 'O' : '#');
        }
        printf("|%c|", i ? '.' : 'D');
        if (i == 0 || i == 2) printf(")");
        printf("\n");
    }
    printf("+------------------------+\n");

    return 0;
}
