/* Verdict: System Error */

// UVa 11732
// strcmp() Anyone?
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int MAXN = 4002;
const int LEN = 1002;

struct Node {
    int head, next, cnt;
    char ch;
};

int T, N;
char S[LEN];

vector<Node> trie;
LL ans;

int insert(char *s, int x) {
    int n = strlen(s), ret = 0, u = 0, v, last = x;
    for (int i = 0; i <= n; i++) {
        for (v = trie[u].head; v; v = trie[v].next) {
            if (trie[v].ch == s[i]) {
                ret += (last - trie[v].cnt) + trie[v].cnt * 2;
                last = trie[v].cnt;
                trie[v].cnt++;
                u = v;
                break;
            }
        }
        if (!v) {
            ret += last;
            last = 0;
            trie.push_back((Node){0, trie[u].head, 1, s[i]});
            trie[u].head = trie.size() - 1;
            u = trie.size() - 1;
        }
    }
    return ret;
};

int main() {
    while (scanf("%d", &N) == 1 && N) {
        ans = 0;
        trie.clear();
        trie.push_back((Node){0, 0, 0, 0});
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            ans += insert(S, i);
        }

        printf("Case %d: %lld\n", ++T, ans);
    }

    return 0;
}
