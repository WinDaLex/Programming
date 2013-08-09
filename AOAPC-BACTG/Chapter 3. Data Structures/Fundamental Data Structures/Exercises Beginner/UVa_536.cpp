// UVa 536
// Tree Recovery
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 28;

char S1[MAXN], S2[MAXN];
int N;

char ans[MAXN];

void build(int n, char *s1, char *s2, char *s) {
    if (n <= 0) return;
    int p = strchr(s2, s1[0]) - s2;

    build(p, s1 + 1, s2, s);
    build(n - p - 1, s1 + p + 1, s2 + p + 1, s + p);
    s[n - 1] = s1[0];
}

int main() {
    while (scanf("%s%s", S1, S2) == 2) {
        N = strlen(S1);

        build(N, S1, S2, ans);

        ans[N] = '\0';
        puts(ans);
    }

    return 0;
}
