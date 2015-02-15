// Codeforces #291 A
// Chewbacca and Number

#include <cstdio>
#include <cstring>

char X[20];

int main() {
    gets(X);
    int l = strlen(X);

    for (int i = 0; i < l; i++) {
        if (X[i] == '9') putchar(i ? '0' : '9');
        else if (X[i] >= '5') putchar('0' + ('9' - X[i]));
        else putchar(X[i]);
    }
    putchar('\n');

    return 0;
}
