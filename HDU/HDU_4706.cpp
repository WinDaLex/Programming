// HDU 4706
// Children's Day
// by A Code Rabbit

#include <cstdio>

char draw[52][11];

void inc(char &ch) {
    ch++;
    if (ch > 'z') ch = 'a';
}

int main() {
    char ch = 'a';
    int x = 0;
    for (int n = 3; n <= 10; n++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                draw[x + i][j] = ' ';
            draw[x + i][n] = '\n';
        }

        for (int i = 0; i < n; i++) {
            draw[x + i][0] = ch;
            inc(ch);
        }
        for (int i = n - 2, j = 1; i >= 1; i--, j++) {
            draw[x + i][j] = ch;
            inc(ch);
        }
        for (int i = 0; i < n; i++) {
            draw[x + i][n - 1] = ch;
            inc(ch);
        }
    
        x += n;
    }

    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 11; j++)
            if (draw[i][j]) putchar(draw[i][j]);

    return 0;
}
