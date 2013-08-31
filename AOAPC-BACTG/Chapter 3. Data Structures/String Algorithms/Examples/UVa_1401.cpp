// UVa 1401
// Remember the Word
// by A Code Rabbit

#include <cstdio>
#include <cstring>

const int MAXN = 300002;
const int MAXM = 4000 * 100 + 2;
const int LEN = 102;
const int ALPHA = 26;
const int MOD = 20071027;

struct Trie {
    int ch[MAXM][ALPHA];
    int val[MAXM];
    int size;
    
    void init() {
        size = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }

    void insert(char *s, int v) {
        int p = 0, n = strlen(s);
        for (int i = 0; i < n; i++) {
            int j = s[i] - 'a';
            if (!ch[p][j]) {
                memset(ch[size], 0, sizeof(ch[size]));
                val[size] = 0;
                ch[p][j] = size++;
            }
            p = ch[p][j];
        }
        val[p] = v;
    }
};

int C, N, M;
char S[MAXN], T[MAXM][LEN];

Trie trie;
int f[MAXN];

int dp(int x) {
    if (x == N) return 1;
    if (f[x] != -1) return f[x];

    int p = 0, ret = 0;
    for (int i = x; i < N; i++) {
        if (!(p = trie.ch[p][S[i] - 'a'])) break;
        if (trie.val[p]) ret = (ret + dp(i + 1)) % MOD;
    }
    return f[x] = ret;
}

int main() {
    while (scanf("%s", S) == 1) {
        N = strlen(S);

        trie.init();
        scanf("%d", &M);
        for (int i = 1; i <= M; i++) {
            scanf("%s", T[i]);
            trie.insert(T[i], i);
        }

        memset(f, -1, sizeof(f));
        printf("Case %d: %d\n", ++C, dp(0));
    }

    return 0;
}
