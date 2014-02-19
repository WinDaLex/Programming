// CF 3D
// Least Cost Bracket Sequence
// by A Code Rabbit

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

const int MAXN = 50002;

struct Question {
    int pos, l, r;
    bool operator<(Question rhs) const {
        return (r - l) < (rhs.r - rhs.l);
    }
};

priority_queue<Question> pq;

int N;
char S[MAXN];

int main() {
    gets(S);
    N = strlen(S);

    LL ans = 0;
    int top = 0, l, r;
    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            scanf("%d%d", &l, &r);
            pq.push((Question){i, l, r});
            ans += r;
            S[i] = ')';
            top--;
        } else {
            top += S[i] == '(' ? 1 : -1;
        }
        if (top < 0) {
            if (pq.empty()) break;
            Question q = pq.top(); pq.pop();
            S[q.pos] = '(';
            ans += q.l - q.r;
            top += 2;
        }
    }

    if (top != 0) {
        puts("-1");
    } else {
        cout << ans << endl;
        puts(S);
    }

    return 0;
}
