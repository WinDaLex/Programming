// UVa 458
// The Decoder
// by A Code Rabbit

#include <cstdio>

char ch;

int main() {
    while ((ch = getchar()) != EOF) {
        putchar(ch == '\n' ? ch : ch + '*' - '1');
    }

    return 0;
}
