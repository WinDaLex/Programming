// UVa 11584
// Partitioning by Palindromes
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1002;
const int INF = 1e9;

int T;
char s[MAXN];

int len;
char str[MAXN][MAXN];
int f[MAXN];

bool is_palindromes(char *str) {
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
        if (str[i] != str[j]) return false;
    return true;
}

int main() {
    scanf("%d", &T);
    getchar();
    while (T--) {
        gets(s);
        len = strlen(s);

        memset(str, 0, sizeof(str));
        f[0] = 0;
        for (int i = 1; i <= len; i++) {
            f[i] = INF;
            for (int j = 0; j < i; j++) {
                str[j][i - 1 - j] = s[i - 1];
                if (is_palindromes(str[j]))
                    f[i] = min(f[j] + 1, f[i]);
            }
        }
        
        printf("%d\n", f[len]);
    }

    return 0;
}
