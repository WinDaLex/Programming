// UVa 445
// Marvelous Mazes
// by A Code Rabbit

#include <cstdio>
#include <cctype>

char ch;

int main() {
    int num = 0;
    while ((ch =getchar()) != EOF) {
        if (isdigit(ch)) {
            num += ch - '0';
        } else
        if (ch == '!' || ch == '\n') {
            putchar('\n');
        } else {
            for (int i = 0; i < num; i++)
                putchar(ch == 'b' ? ' ' : ch);
            num = 0;
        }
    }

    return 0;
}
