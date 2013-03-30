// UVa 457
// Linear Cellular Automata
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const char MAP[] = {' ', '.', 'x', 'W'};

int dna[10];
int dish[40];

int main() {
    int T;
    scanf("%d", &T);
    bool first = true;
    while (T--) {
        for (int i = 0; i < 10; i++)
            scanf("%d", &dna[i]);

        memset(dish, 0, sizeof(dish));
        dish[19] = 1;

        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 40; j++)
                printf("%c", MAP[dish[j]]);
            printf("\n");

            int tmp[40];
            for (int j = 0; j < 40; j++) {
                int sum = dish[j];
                if (j > 0) sum += dish[j - 1];
                if (j < 39) sum += dish[j + 1];
                tmp[j] = dna[sum];
            }
            memcpy(dish, tmp, sizeof(tmp));
        }
        printf("%s", T ? "\n" : "");
    }

    return 0;
}
