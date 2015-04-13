// Codeforces 518A
// Vitaly and Strings

#include <cstdio>
#include <cstring>

const int LEN = 102;

char S[LEN], T[LEN];
int len;

char ans[LEN];

int main() {
    scanf("%s%s", S, T);
    len = strlen(S);

    if (strcmp(S, T) >= 0) {
        puts("No such string");
        return 0;
    }

    strcat(ans, S);

    int i = len - 1;
    ans[i]++;
    while (ans[i] > 'z') {
        ans[i] = 'a';
        if (i > 0) ans[--i]++;
        else {
            puts("No such string");
            return 0;
        }
    }

    if (strcmp(ans, T) < 0) {
        puts(ans);
    } else {
        puts("No such string");

    }

    return 0;
}
