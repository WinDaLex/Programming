// UVa 10391
// Compound Words
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 120002;
const int LEN = 102;
const int SIZE = 1000003;

int N = 0;
char word[MAXN][LEN];

int head[SIZE];
int next[MAXN];

int hash(const char *str) {
    int res = 0;
    while (*str) res = res * 26 + (*str++ - 'a' + 1);
    return res % SIZE;
}

void insert(int x) {
    int h = hash(word[x]);
    next[x] = head[h];
    head[h] = x;
}

bool search(const char *str) {
    int h = hash(str);
    int u = head[h];
    while (u != -1) {
        if (strcmp(str, word[u]) == 0) return true;
        u = next[u];
    }
    return false;
}

bool check(char *str, int x) {
    int len = strlen(str);
    char left[LEN], right[LEN];
    strncpy(left, str, x);
    left[x] = '\0';
    strncpy(right, str + x, len - x);
    right[len - x] = '\0';

    if (search(left) && search(right)) return true;
    else return false;
}

int main() {
    while (gets(word[N])) N++;

    memset(head, -1, sizeof(head));
    for (int i = 0; i < N; i++)
        insert(i);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < strlen(word[i]); j++) {
            if (check(word[i], j)) {
                puts(word[i]);
                break;
            }
        }
    }

    return 0;
}
