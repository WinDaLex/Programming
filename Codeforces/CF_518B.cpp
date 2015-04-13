// Codeforces 518B
// Tanya and Postcard

#include <cstdio>
#include <cstring>
#include <cctype>

const int MAXN = 2e5 + 2;

char S[MAXN];
char T[MAXN];

int upper[26];
int lower[26];

char rest[MAXN];
int top;

int main() {
    scanf("%s%s", S, T);
    int n = strlen(S), m = strlen(T);

    for (int i = 0; i < m; i++) {
        if (isupper(T[i])) upper[T[i] - 'A']++;
        else lower[T[i] - 'a']++;
    }

    int first = 0, second = 0;
    top = 0;
    for (int i = 0; i < n; i++) {
        if (isupper(S[i])) {
            if (upper[S[i] - 'A']) {
                first++;
                upper[S[i] - 'A']--;
            } else {
                rest[top++] = S[i];
            }
        } else {
            if (lower[S[i] - 'a']) {
                first++;
                lower[S[i] - 'a']--;
            } else {
                rest[top++] = S[i];
            }
        }
    }

    for (int i = 0; i < top; i++) {
        if (isupper(rest[i])) {
            if (lower[rest[i] - 'A']) {
                second++;
                lower[rest[i] - 'A']--;
            }
        } else {
            if (upper[rest[i] - 'a']) {
                second++;
                upper[rest[i] - 'a']--;
            }
        }
    }

    printf("%d %d\n", first, second);

    return 0;
}
