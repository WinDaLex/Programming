// UVa 12050
// Palindrome Numbers
// by A Code Rabbit

#include <cstdio>

const int MAXA = 20;
const int AREA[MAXA] = {
    0, 9, 18, 108, 198, 1098, 1998, 10998, 19998, 109998,
    199998, 1099998, 1999998, 10999998, 19999998, 109999998, 199999998, 1099999998, 1999999998, 2e9
};

const int TEN[MAXA] = {
    1e0, 1e0, 1e0, 1e1, 1e1, 1e2, 1e2, 1e3, 1e3, 1e4,
    1e4, 1e5, 1e5, 1e6, 1e6, 1e7, 1e7, 1e8, 1e8, 1e9
};

int N;

int digit;

int main() {
    while (scanf("%d", &N) && N) {
        for (digit = 0; N > AREA[digit]; digit++)
            ;

        int x = N - AREA[digit - 1] + TEN[digit] - 1;

        printf("%d", x);
        if (digit % 2) x /= 10;
        while (x) {
            printf("%d", x % 10);
            x /= 10;
        }
        printf("\n");
    }

    return 0;
}
