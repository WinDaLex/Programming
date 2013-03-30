// UVa 494
// Kindergarten Counting Game
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <cctype>

char str[10000];

int main() {
    while (gets(str)) {
        int ans = 0;
        for (int i = 0; i < strlen(str); i++)
            if (isalpha(str[i]) && (!i || !isalpha(str[i - 1])))
                ans++;
        printf("%d\n", ans);
    }

    return 0;
}
