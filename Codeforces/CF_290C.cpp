// Codeforces #290 C
// Fox And Names

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 102;
const int MAXLEN = 102;

int N;
char name[MAXN][MAXLEN];

int le[26][26];
int d[26];

int sta[26], top;
char ans[27];
int len;

bool make_less(char s1[], char s2[]) {
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < min(l1, l2); i++) {
        if (s1[i] != s2[i]) {
            if (!le[s1[i] - 'a'][s2[i] - 'a']) {
                le[s1[i] - 'a'][s2[i] - 'a'] = true;
                d[s2[i] - 'a']++;
            }
            return true;
        }
    }
    return l1 < l2;
}

bool kahn() {
    for (int i = 0; i < 26; i++)
        if (!d[i]) sta[top++] = i;

    while (top) {
        int x = sta[--top];
        ans[len++] = x + 'a';
        for (int i = 0; i < 26; i++)
            if (d[i] && le[x][i])
                if (--d[i] == 0)
                    sta[top++] = i;
    }

    return strlen(ans) == 26;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", name[i]);

    bool bo = false;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (!make_less(name[i], name[j]))
                bo = true;
    
    if (!bo && kahn()) puts(ans);
    else puts("Impossible");

    return 0;
}
