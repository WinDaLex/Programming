// UVa 10340
// All in All
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int LEN = 100002;

char s[LEN], t[LEN];

int main() {
    while (scanf("%s%s", s, t) != EOF) {
        int idx = 0;
        for (int i = 0; i < strlen(t); i++)
            if (t[i] == s[idx]) idx++;
        puts(idx == strlen(s) ? "Yes" : "No");
    }

    return 0;
}
