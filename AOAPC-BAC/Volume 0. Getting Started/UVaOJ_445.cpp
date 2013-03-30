// UVaOJ 445
// Marvelous Mazes
// by A Code Rabbit

#include <cstdio>

char ch;
int num;

int main() {
    num = 0;
    while (scanf("%c", &ch) != EOF) {
        if ('0' <= ch && ch <= '9')
            num += ch - '0';
        else if (ch == '!' || ch == '\n')
            putchar('\n');
        else {
            for (int i = 0; i < num; i++)
                putchar(ch == 'b' ? ' ' : ch);
            num = 0;
        }
    }

    return 0;
}
