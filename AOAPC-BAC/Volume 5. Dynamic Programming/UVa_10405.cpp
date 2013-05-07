// UVa 10405
// Longest Common Subsequence
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int LEN = 1002;

char S1[LEN], S2[LEN];

int len1, len2;
int f[LEN][LEN];

int main() {
    while (gets(S1)) {
        gets(S2);

        len1 = strlen(S1);
        len2 = strlen(S2);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++)
                f[i][j] = S1[i - 1] == S2[j - 1] ? f[i - 1][j - 1] + 1 : max(f[i - 1][j], f[i][j - 1]);

        printf("%d\n", f[len1][len2]);
    }

    return 0;
}
