// UVa 490
// Rotating Sentences
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;

char str[MAXN][MAXN];

int main() {
    int top = 0, max_len = 0;
    while (gets(str[top])) {
        max_len = max(max_len, (int)strlen(str[top]));
        top++;
    }

    for (int i = 0; i < max_len; i++) {
        for (int j = top - 1; j >= 0; j--)
            printf("%c", str[j][i] ? str[j][i] : ' ');
        printf("\n");
    }

    return 0;
}
